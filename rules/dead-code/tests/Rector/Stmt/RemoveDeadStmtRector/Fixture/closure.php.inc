<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

function wrapToPreventPhpStanCallingMethods ()
{
    $a = function () {};
    function () {};
}
?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

function wrapToPreventPhpStanCallingMethods ()
{
    $a = function () {};
}
?>
