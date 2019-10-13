<?php

declare(strict_types=1);

namespace Rector\Rector\Property;

use PhpParser\Node;
use PhpParser\Node\Expr\PropertyFetch;
use PhpParser\Node\Identifier;
use Rector\Rector\AbstractRector;
use Rector\RectorDefinition\ConfiguredCodeSample;
use Rector\RectorDefinition\RectorDefinition;

/**
 * @see \Rector\Tests\Rector\Property\RenamePropertyRector\RenamePropertyRectorTest
 */
final class RenamePropertyRector extends AbstractRector
{
    /**
     * class => [
     *     oldProperty => newProperty
     * ]
     *
     * @var string[][]
     */
    private $oldToNewPropertyByTypes = [];

    /**
     * @param string[][] $oldToNewPropertyByTypes
     */
    public function __construct(array $oldToNewPropertyByTypes = [])
    {
        $this->oldToNewPropertyByTypes = $oldToNewPropertyByTypes;
    }

    public function getDefinition(): RectorDefinition
    {
        return new RectorDefinition('Replaces defined old properties by new ones.', [
            new ConfiguredCodeSample(
                '$someObject->someOldProperty;',
                '$someObject->someNewProperty;',
                [
                    '$oldToNewPropertyByTypes' => [
                        'SomeClass' => [
                            'someOldProperty' => 'someNewProperty',
                        ],
                    ],
                ]
            ),
        ]);
    }

    /**
     * @return string[]
     */
    public function getNodeTypes(): array
    {
        return [PropertyFetch::class];
    }

    /**
     * @param PropertyFetch $node
     */
    public function refactor(Node $node): ?Node
    {
        foreach ($this->oldToNewPropertyByTypes as $type => $oldToNewProperties) {
            if (! $this->isObjectType($node->var, $type)) {
                continue;
            }

            foreach ($oldToNewProperties as $oldProperty => $newProperty) {
                if (! $this->isName($node, $oldProperty)) {
                    continue;
                }

                $node->name = new Identifier($newProperty);
            }
        }

        return $node;
    }
}
