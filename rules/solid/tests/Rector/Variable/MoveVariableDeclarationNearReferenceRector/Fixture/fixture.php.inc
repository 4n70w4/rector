<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SomeClass
{
    function myMethod()
    {
        $var = 1;
        if (mktime() === false) {
            return $var;
        }
    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SomeClass
{
    function myMethod()
    {
        if (mktime() === false) {
            $var = 1;
            return $var;
        }
    }
}

?>
