<?php declare(strict_types=1);

namespace Rector\PhpParser\Node\Manipulator;

use PhpParser\Node;
use PhpParser\Node\Expr\PropertyFetch;
use PhpParser\Node\Expr\StaticPropertyFetch;
use PhpParser\Node\Stmt\Property;
use Rector\NodeTypeResolver\Node\AttributeKey;
use Rector\PhpParser\Node\BetterNodeFinder;
use Rector\PhpParser\Node\Resolver\NameResolver;
use Rector\PhpParser\Printer\BetterStandardPrinter;

/**
 * "private $property"
 */
final class PropertyManipulator
{
    /**
     * @var BetterNodeFinder
     */
    private $betterNodeFinder;

    /**
     * @var BetterStandardPrinter
     */
    private $betterStandardPrinter;

    /**
     * @var NameResolver
     */
    private $nameResolver;

    public function __construct(
        BetterNodeFinder $betterNodeFinder,
        BetterStandardPrinter $betterStandardPrinter,
        NameResolver $nameResolver
    ) {
        $this->betterNodeFinder = $betterNodeFinder;
        $this->betterStandardPrinter = $betterStandardPrinter;
        $this->nameResolver = $nameResolver;
    }

    /**
     * @return PropertyFetch[]
     */
    public function getAllPropertyFetch(Property $property): array
    {
        $classNode = $property->getAttribute(AttributeKey::CLASS_NODE);
        if ($classNode === null) {
            return [];
        }

        return $this->betterNodeFinder->find($classNode, function (Node $node) use ($property) {
            // itself
            if ($this->betterStandardPrinter->areNodesEqual($node, $property)) {
                return null;
            }

            // property + static fetch
            if (! $node instanceof PropertyFetch && ! $node instanceof StaticPropertyFetch) {
                return null;
            }

            // is it the name match?
            if (! $this->nameResolver->areNamesEqual($node, $property)) {
                return null;
            }

            return $node;
        });
    }
}
