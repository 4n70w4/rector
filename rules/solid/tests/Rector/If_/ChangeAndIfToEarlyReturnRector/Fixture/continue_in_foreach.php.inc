<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

use PhpParser\Node\Identifier;
use PhpParser\Node\Name;

class ContinueInForeachClass
{
    private function refactorStmts(array $nodes): void
    {
        foreach ($nodes as $node) {
            if ($node instanceof Name && $node instanceof Identifier) {
                $this->processNameOrIdentifier($node);
            }
        }
    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

use PhpParser\Node\Identifier;
use PhpParser\Node\Name;

class ContinueInForeachClass
{
    private function refactorStmts(array $nodes): void
    {
        foreach ($nodes as $node) {
            if (!$node instanceof Name) {
                continue;
            }
            if (!$node instanceof Identifier) {
                continue;
            }
            $this->processNameOrIdentifier($node);
        }
    }
}

?>
