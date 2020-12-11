<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

function variableInClosureWithReturn()
{
    return function () {
        $var = 1;
        if (mktime() === false) {
            return $var;
        }
    };
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

function variableInClosureWithReturn()
{
    return function () {
        if (mktime() === false) {
            $var = 1;
            return $var;
        }
    };
}

?>
