<?php declare(strict_types=1);

namespace Rector\Rector\Contrib\PhpParser;

use PhpParser\Node;
use PhpParser\Node\Expr\PropertyFetch;
use PhpParser\Node\Expr\Variable;
use PhpParser\Node\Identifier;
use Rector\Node\Attribute;
use Rector\Node\PropertyFetchNodeFactory;
use Rector\NodeAnalyzer\PropertyFetchAnalyzer;
use Rector\Rector\AbstractRector;

/**
 * Before:
 * - $catchNode->var
 *
 * After:
 * - $catchNode->var->name
 */
final class CatchAndClosureUseNameRector extends AbstractRector
{
    /**
     * @var PropertyFetchAnalyzer
     */
    private $propertyFetchAnalyzer;

    /**
     * @var PropertyFetchNodeFactory
     */
    private $propertyFetchNodeFactory;

    public function __construct(
        PropertyFetchAnalyzer $propertyFetchAnalyzer,
        PropertyFetchNodeFactory $propertyFetchNodeFactory
    ) {
        $this->propertyFetchAnalyzer = $propertyFetchAnalyzer;
        $this->propertyFetchNodeFactory = $propertyFetchNodeFactory;
    }

    public function isCandidate(Node $node): bool
    {
        return $this->propertyFetchAnalyzer->isTypesAndProperty(
            $node,
            ['PhpParser\Node\Stmt\Catch_', 'PhpParser\Node\Expr\ClosureUse'],
            'var'
        );
    }

    /**
     * @param PropertyFetch $propertyFetchNode
     */
    public function refactor(Node $propertyFetchNode): ?Node
    {
        $parentNode = $propertyFetchNode->getAttribute(Attribute::PARENT_NODE);
        if ($parentNode instanceof PropertyFetch) {
            return $propertyFetchNode;
        }

        /** @var Variable $variableNode */
        $variableNode = $propertyFetchNode->var;

        $propertyFetchNode->var = $this->propertyFetchNodeFactory->createWithVariableNameAndPropertyName(
            (string) $variableNode->name,
            'var'
        );
        $propertyFetchNode->name = new Identifier('name');

        return $propertyFetchNode;
    }
}
