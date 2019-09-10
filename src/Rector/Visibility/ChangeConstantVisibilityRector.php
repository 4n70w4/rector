<?php declare(strict_types=1);

namespace Rector\Rector\Visibility;

use PhpParser\Node;
use PhpParser\Node\Stmt\ClassConst;
use Rector\Rector\AbstractRector;
use Rector\RectorDefinition\ConfiguredCodeSample;
use Rector\RectorDefinition\RectorDefinition;

/**
 * @see \Rector\Tests\Rector\Visibility\ChangeConstantVisibilityRector\ChangeConstantVisibilityRectorTest
 */
final class ChangeConstantVisibilityRector extends AbstractRector
{
    /**
     * @var string[][] { class => [ method name => visibility ] }
     */
    private $constantToVisibilityByClass = [];

    /**
     * @param string[][] $constantToVisibilityByClass
     */
    public function __construct(array $constantToVisibilityByClass = [])
    {
        $this->constantToVisibilityByClass = $constantToVisibilityByClass;
    }

    public function getDefinition(): RectorDefinition
    {
        return new RectorDefinition(
            'Change visibility of constant from parent class.',
            [new ConfiguredCodeSample(
                <<<'CODE_SAMPLE'
class FrameworkClass
{
    protected const SOME_CONSTANT = 1;
}

class MyClass extends FrameworkClass
{
    public const SOME_CONSTANT = 1;
}
CODE_SAMPLE
                ,
                <<<'CODE_SAMPLE'
class FrameworkClass
{
    protected const SOME_CONSTANT = 1;
}

class MyClass extends FrameworkClass
{
    protected const SOME_CONSTANT = 1;
}
CODE_SAMPLE
                ,
                [
                    'ParentObject' => [
                        'SOME_CONSTANT' => 'protected',
                    ],
                ]
            )]
        );
    }

    /**
     * @return string[]
     */
    public function getNodeTypes(): array
    {
        return [ClassConst::class];
    }

    /**
     * @param ClassConst $node
     */
    public function refactor(Node $node): ?Node
    {
        foreach ($this->constantToVisibilityByClass as $class => $constantsToVisibility) {
            if (! $this->isObjectType($node, $class)) {
                continue;
            }

            foreach ($constantsToVisibility as $constant => $visibility) {
                if (! $this->isName($node, $constant)) {
                    continue;
                }

                $this->changeNodeVisibility($node, $visibility);

                return $node;
            }
        }

        return null;
    }
}
