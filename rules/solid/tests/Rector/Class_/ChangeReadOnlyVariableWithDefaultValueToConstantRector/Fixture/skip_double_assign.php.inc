<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SkipDoubleAssign
{
    protected function run()
    {
        $a = $b = $c = $d = '';
    }
}
