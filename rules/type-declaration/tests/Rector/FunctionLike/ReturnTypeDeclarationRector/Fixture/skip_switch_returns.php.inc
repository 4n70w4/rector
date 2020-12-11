<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SkipSwtichReturns
{
    public function someFunction($value)
    {
        switch ($value) {
            case (1):
                return 'one';
            case (2):
                return 'two';
        }
    }
}
