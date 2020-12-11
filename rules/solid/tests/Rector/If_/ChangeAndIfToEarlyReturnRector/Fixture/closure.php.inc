<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

use PhpParser\Node;
use PhpParser\Node\Identifier;
use PhpParser\Node\Name;

class ClosureClass
{
    private function refactorStmts(array $nodes): array
    {
        $this->traverseNodesWithCallable($nodes, function (Node $node) {
            if ($node instanceof Name && $node instanceof Identifier) {
                $this->processNameOrIdentifier($node);
            }

            return;
        });

        return $nodes;
    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

use PhpParser\Node;
use PhpParser\Node\Identifier;
use PhpParser\Node\Name;

class ClosureClass
{
    private function refactorStmts(array $nodes): array
    {
        $this->traverseNodesWithCallable($nodes, function (Node $node) {
            if (!$node instanceof Name) {
                return;
            }
            if (!$node instanceof Identifier) {
                return;
            }
            $this->processNameOrIdentifier($node);
        });

        return $nodes;
    }
}

?>
