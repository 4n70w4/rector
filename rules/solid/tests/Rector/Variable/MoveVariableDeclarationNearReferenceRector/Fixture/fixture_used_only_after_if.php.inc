<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SomeClassUsedOnlyAfterIf
{
    function myMethod()
    {
        $var = 1;
        if (mktime() === false) {
            null;
        }
        return $var;
    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SomeClassUsedOnlyAfterIf
{
    function myMethod()
    {
        if (mktime() === false) {
            null;
        }
        $var = 1;
        return $var;
    }
}

?>
