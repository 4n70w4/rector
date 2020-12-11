<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SkipSingleLine
{
    public function run()
    {
        $items = [];

        foreach ($values as $value) {
            if ($value === 5) {
                $items[] = 'maybe';
            }
        }
    }
}
