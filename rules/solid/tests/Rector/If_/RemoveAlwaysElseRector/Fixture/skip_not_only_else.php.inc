<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SkipNotOnlyElse
{

    public function runAgainAndAgain($value)
    {
        if ($value) {
            5 + 10;
        } else {
            return $value;
        }
    }
}
