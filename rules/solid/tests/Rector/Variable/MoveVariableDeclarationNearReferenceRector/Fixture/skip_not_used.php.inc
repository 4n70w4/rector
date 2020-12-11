<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SkipNotUsed
{
    function myMethod()
    {
        $var = 1;

        if (mktime() === false) {

        }
    }
}

?>
