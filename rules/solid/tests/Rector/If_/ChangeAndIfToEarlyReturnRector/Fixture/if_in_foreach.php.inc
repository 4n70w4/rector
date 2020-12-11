<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

use PhpParser\Node\Identifier;
use PhpParser\Node\Name;

class IfInForeachClass
{
    private function refactorStmts(array $nodes): void
    {
        foreach ($nodes as $node) {
            if ($node instanceof Name && $node instanceof Identifier) {
                $this->processNameOrIdentifier($node);
            }

            return;
        }

        return;
    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

use PhpParser\Node\Identifier;
use PhpParser\Node\Name;

class IfInForeachClass
{
    private function refactorStmts(array $nodes): void
    {
        foreach ($nodes as $node) {
            if (!$node instanceof Name) {
                return;
            }
            if (!$node instanceof Identifier) {
                return;
            }
            $this->processNameOrIdentifier($node);
            return;
        }

        return;
    }
}

?>
