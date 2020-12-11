<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

use PhpParser\Node\Identifier;
use PhpParser\Node\Name;

class SkipNestedIfInLoop
{
    private function refactorStmts(array $nodes): void
    {
        $g = [];

        foreach ($nodes as $node) {
            $x = ['A', 'B'];
            if (rand(1,2)) {
                // something
            } else {
                if ($node instanceof Name && $node instanceof Identifier) {
                    $x = [];
                }
            }

            $g = $x;
        }
    }
}

?>
