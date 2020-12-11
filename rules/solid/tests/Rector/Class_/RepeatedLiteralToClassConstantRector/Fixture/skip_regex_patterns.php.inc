<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SkipRegexPatterns
{
    public function run($key, $items)
    {
        if ($key === '$') {
            return $items['$'];
        }

        return $items['$'];
    }
}
