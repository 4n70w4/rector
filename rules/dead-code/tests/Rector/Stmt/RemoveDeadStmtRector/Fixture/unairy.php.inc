<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

function wrapToPreventPhpStanCallingMethods ()
{
    $a = -$a;
    $a = +$a;
    $a = !$a;
    $a = ~$a;

    -$a;
    +$a;
    !$a;
    ~$a;
}
?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

function wrapToPreventPhpStanCallingMethods ()
{
    $a = -$a;
    $a = +$a;
    $a = !$a;
    $a = ~$a;
}
?>
