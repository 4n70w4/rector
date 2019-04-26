<?php declare(strict_types=1);

namespace Rector\DeadCode\Rector\Property;

use PhpParser\Node;
use PhpParser\Node\Expr\Assign;
use PhpParser\Node\Expr\PropertyFetch;
use PhpParser\Node\Stmt\Property;
use Rector\NodeTypeResolver\Node\AttributeKey;
use Rector\PhpParser\Node\Manipulator\PropertyManipulator;
use Rector\Rector\AbstractRector;
use Rector\RectorDefinition\CodeSample;
use Rector\RectorDefinition\RectorDefinition;

final class RemoveUnusedPrivatePropertyRector extends AbstractRector
{
    /**
     * @var PropertyManipulator
     */
    private $propertyManipulator;

    public function __construct(PropertyManipulator $propertyManipulator)
    {
        $this->propertyManipulator = $propertyManipulator;
    }

    public function getDefinition(): RectorDefinition
    {
        return new RectorDefinition('Remove unused private properties', [
            new CodeSample(
                <<<'CODE_SAMPLE'
class SomeClass
{
    private $property;
}
CODE_SAMPLE
                ,
                <<<'CODE_SAMPLE'
class SomeClass
{
}
CODE_SAMPLE
            ),
        ]);
    }

    /**
     * @return string[]
     */
    public function getNodeTypes(): array
    {
        return [Property::class];
    }

    /**
     * @param Property $node
     */
    public function refactor(Node $node): ?Node
    {
        if (! $node->isPrivate()) {
            return null;
        }

        $classNode = $node->getAttribute(AttributeKey::CLASS_NODE);
        if ($classNode instanceof Node\Stmt\Trait_) {
            return null;
        }

        if (count($node->props) !== 1) {
            return null;
        }

        $propertyFetches = $this->propertyManipulator->getAllPropertyFetch($node);

        // never used
        if ($propertyFetches === []) {
            $this->removeNode($node);
        }

        $uselessAssigns = $this->resolveUselessAssignNode($propertyFetches);

        if (count($uselessAssigns) > 0) {
            $this->removeNode($node);
            foreach ($uselessAssigns as $uselessAssign) {
                $this->removeNode($uselessAssign);
            }
        }

        return $node;
    }

    /**
     * @param PropertyFetch[] $propertyFetches
     * @return Assign[]
     */
    private function resolveUselessAssignNode(array $propertyFetches): array
    {
        $uselessAssigns = [];

        foreach ($propertyFetches as $propertyFetch) {
            $propertyFetchParentNode = $propertyFetch->getAttribute(AttributeKey::PARENT_NODE);
            if ($propertyFetchParentNode instanceof Assign && $propertyFetchParentNode->var === $propertyFetch) {
                $uselessAssigns[] = $propertyFetchParentNode;
            } else {
                return [];
            }
        }

        return $uselessAssigns;
    }
}
