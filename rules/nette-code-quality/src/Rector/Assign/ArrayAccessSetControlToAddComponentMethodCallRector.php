<?php

declare(strict_types=1);

namespace Rector\NetteCodeQuality\Rector\Assign;

use PhpParser\Node;
use PhpParser\Node\Expr\ArrayDimFetch;
use PhpParser\Node\Expr\Assign;
use PhpParser\Node\Expr\MethodCall;
use PhpParser\Node\Expr\Variable;
use PHPStan\Type\ObjectType;
use Rector\Core\Rector\AbstractRector;
use Rector\Core\RectorDefinition\CodeSample;
use Rector\Core\RectorDefinition\RectorDefinition;

/**
 * @sponsor Thanks https://amateri.com for sponsoring this rule - visit them on https://www.startupjobs.cz/startup/scrumworks-s-r-o
 *
 * @see \Rector\NetteCodeQuality\Tests\Rector\Assign\ArrayAccessSetControlToAddComponentMethodCallRector\ArrayAccessSetControlToAddComponentMethodCallRectorTest
 *
 * @see https://github.com/nette/component-model/blob/c1fb11729423379768a71dd865ae373a3b12fa43/src/ComponentModel/Container.php#L39
 */
final class ArrayAccessSetControlToAddComponentMethodCallRector extends AbstractRector
{
    public function getDefinition(): RectorDefinition
    {
        return new RectorDefinition('Change magic arrays access set, to explicit $this->setComponent(...) method', [
            new CodeSample(
                <<<'PHP'
use Nette\Application\UI\Control;
use Nette\Application\UI\Presenter;

class SomeClass extends Presenter
{
    public function some()
    {
        $someControl = new Control();
        $this['whatever'] = $someControl;
    }
}
PHP
,
                <<<'PHP'
use Nette\Application\UI\Control;
use Nette\Application\UI\Presenter;

class SomeClass extends Presenter
{
    public function some()
    {
        $someControl = new Control();
        $this->addComponent($someControl, 'whatever');
    }
}
PHP
            ),
        ]);
    }

    /**
     * @return string[]
     */
    public function getNodeTypes(): array
    {
        return [Assign::class];
    }

    /**
     * @param Assign $node
     */
    public function refactor(Node $node): ?Node
    {
        if (! $this->isAssignOfControlToPresenterDimFetch($node)) {
            return null;
        }

        /** @var ArrayDimFetch $arrayDimFetch */
        $arrayDimFetch = $node->var;

        $arguments = [$node->expr, $arrayDimFetch->dim];

        $arg = $this->createArgs($arguments);

        return new MethodCall($arrayDimFetch->var, 'addComponent', $arg);
    }

    private function isAssignOfControlToPresenterDimFetch(Assign $assign): bool
    {
        if (! $assign->var instanceof ArrayDimFetch) {
            return false;
        }

        $exprStaticType = $this->getObjectType($assign->expr);
        if (! $exprStaticType->isSuperTypeOf(new ObjectType('Nette\Application\UI\Control'))->yes()) {
            return false;
        }

        $arrayDimFetch = $assign->var;
        if (! $arrayDimFetch->var instanceof Variable) {
            return false;
        }

        $variableStaticType = $this->getObjectType($arrayDimFetch->var);
        return $variableStaticType->isSuperTypeOf(new ObjectType('Nette\Application\UI\Presenter'))->yes();
    }
}