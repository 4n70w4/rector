<?php declare(strict_types=1);

namespace Rector\NodeTypeResolver\Tests\PerNodeTypeResolver\ParamTypeResolver;

use PhpParser\Node\Expr\Variable;
use Rector\Node\Attribute;
use Rector\NodeTypeResolver\Tests\AbstractNodeTypeResolverTest;

final class Test extends AbstractNodeTypeResolverTest
{
    public function testTypehint(): void
    {
        $variableNodes = $this->getNodesForFileOfType(__DIR__ . '/Source/MethodParamTypeHint.php.inc', Variable::class);

        $this->assertSame(
            ['SomeNamespace\SubNamespace\Html'],
            $variableNodes[0]->getAttribute(Attribute::TYPES)
        );
    }

    public function testDocBlock(): void
    {
        $variableNodes = $this->getNodesForFileOfType(__DIR__ . '/Source/MethodParamDocBlock.php.inc', Variable::class);

        $this->assertSame(
            ['SomeNamespace\SubNamespace\Html'],
            $variableNodes[0]->getAttribute(Attribute::TYPES)
        );
    }
}
