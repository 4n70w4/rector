<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SkipExprVarUsed
{
    function myMethod()
    {
        $var = run($a, $b);
        $a = 1;
        $b = 2;

        if (mktime() === false) {
            return $var;
        }
    }
}

?>