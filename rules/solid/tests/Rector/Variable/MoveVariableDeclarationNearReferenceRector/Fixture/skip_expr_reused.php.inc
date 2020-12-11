<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SkipExprReused
{
    function myMethod($x)
    {
        $var = $x;
        $x = 1;
        echo $var;
    }
}

?>
