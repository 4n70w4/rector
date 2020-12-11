<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SkipVoidAndOther
{
    public function getSome($value)
    {
        if ($value !== 5) {
            return;
        }

        return $value !== 10;
    }
}
