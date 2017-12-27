<?php declare(strict_types=1);

namespace Rector\NodeTypeResolver\Tests\PerNodeTypeResolver\VariableTypeResolver;

use PhpParser\Node\Expr\Variable;
use Rector\Node\Attribute;
use Rector\NodeTypeResolver\Tests\AbstractNodeTypeResolverTest;

final class Test extends AbstractNodeTypeResolverTest
{
    public function testThis(): void
    {
        $variableNodes = $this->getNodesForFileOfType(__DIR__ . '/Source/This.php.inc', Variable::class);

        $this->assertSame(
            ['SomeNamespace\SomeClass', 'SomeNamespace\AnotherClass'],
            $variableNodes[0]->getAttribute(Attribute::TYPES)
        );
    }

    public function testNew(): void
    {
        $variableNodes = $this->getNodesForFileOfType(__DIR__ . '/Source/SomeClass.php.inc', Variable::class);

        $this->assertSame(
            ['SomeNamespace\AnotherType'],
            $variableNodes[0]->getAttribute(Attribute::TYPES)
        );
        $this->assertSame(
            ['SomeNamespace\AnotherType'],
            $variableNodes[2]->getAttribute(Attribute::TYPES)
        );
    }

    public function testAssign(): void
    {
        $variableNodes = $this->getNodesForFileOfType(__DIR__ . '/Source/SomeClass.php.inc', Variable::class);

        $this->assertSame(
            ['SomeNamespace\AnotherType'],
            $variableNodes[1]->getAttribute(Attribute::TYPES)
        );
    }

    public function testCallbackArgumentTypehint(): void
    {
        $variableNodes = $this->getNodesForFileOfType(__DIR__ . '/Source/ArgumentTypehint.php.inc', Variable::class);

        $this->assertSame(
            ['SomeNamespace\UseUse'],
            $variableNodes[0]->getAttribute(Attribute::TYPES)
        );
        $this->assertSame(
            ['SomeNamespace\UseUse'],
            $variableNodes[1]->getAttribute(Attribute::TYPES)
        );
    }
}
