<?php

declare(strict_types=1);

namespace Rector\Php70\Rector\StaticCall;

use PhpParser\Node;
use PhpParser\Node\Expr\MethodCall;
use PhpParser\Node\Expr\New_;
use PhpParser\Node\Expr\StaticCall;
use Rector\NodeContainer\ParsedNodesByType;
use Rector\NodeTypeResolver\Node\AttributeKey;
use Rector\PhpParser\Node\Manipulator\ClassMethodManipulator;
use Rector\Rector\AbstractRector;
use Rector\RectorDefinition\CodeSample;
use Rector\RectorDefinition\RectorDefinition;
use ReflectionClass;

/**
 * @see https://thephp.cc/news/2017/07/dont-call-instance-methods-statically
 * @see https://3v4l.org/tQ32f
 * @see https://3v4l.org/jB9jn
 * @see https://stackoverflow.com/a/19694064/1348344
 * @see \Rector\Php70\Tests\Rector\StaticCall\StaticCallOnNonStaticToInstanceCallRector\StaticCallOnNonStaticToInstanceCallRectorTest
 */
final class StaticCallOnNonStaticToInstanceCallRector extends AbstractRector
{
    /**
     * @var ParsedNodesByType
     */
    private $parsedNodesByType;

    /**
     * @var ClassMethodManipulator
     */
    private $classMethodManipulator;

    public function __construct(
        ParsedNodesByType $parsedNodesByType,
        ClassMethodManipulator $classMethodManipulator
    ) {
        $this->parsedNodesByType = $parsedNodesByType;
        $this->classMethodManipulator = $classMethodManipulator;
    }

    public function getDefinition(): RectorDefinition
    {
        return new RectorDefinition('Changes static call to instance call, where not useful', [
            new CodeSample(
                <<<'PHP'
class Something
{
    public function doWork()
    {
    }
}

class Another
{
    public function run()
    {
        return Something::doWork();
    }
}
PHP
                ,
                <<<'PHP'
class Something
{
    public function doWork()
    {
    }
}

class Another
{
    public function run()
    {
        return (new Something)->doWork();
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
        return [StaticCall::class];
    }

    /**
     * @param StaticCall $node
     */
    public function refactor(Node $node): ?Node
    {
        $methodName = $this->getName($node);
        $className = $this->getName($node->class);
        if ($methodName === null || $className === null) {
            return null;
        }

        $isStaticMethod = $this->parsedNodesByType->isStaticMethod($methodName, $className);
        if ($isStaticMethod) {
            return null;
        }

        if ($this->isNames($node->class, ['self', 'parent', 'static'])) {
            return null;
        }

        $className = $this->getName($node->class);
        $parentClassName = $node->getAttribute(AttributeKey::PARENT_CLASS_NAME);
        if ($className === $parentClassName) {
            return null;
        }

        if ($className === null) {
            return null;
        }

        if ($this->isInstantiable($node)) {
            $newNode = new New_($node->class);

            return new MethodCall($newNode, $node->name, $node->args);
        }

        // can we add static to method?
        $classMethodNode = $this->parsedNodesByType->findMethod($methodName, $className);
        if ($classMethodNode === null) {
            return null;
        }

        if ($this->classMethodManipulator->isStaticClassMethod($classMethodNode)) {
            return null;
        }

        $this->makeStatic($classMethodNode);

        return null;
    }

    private function isInstantiable(StaticCall $staticCall): bool
    {
        $className = $this->getName($staticCall->class);

        $reflectionClass = new ReflectionClass($className);
        $classConstructorReflection = $reflectionClass->getConstructor();

        if ($classConstructorReflection === null) {
            return true;
        }

        if (! $classConstructorReflection->isPublic()) {
            return false;
        }

        // required parameters in constructor, nothing we can do
        return ! (bool) $classConstructorReflection->getNumberOfRequiredParameters();
    }
}
