<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

function wrapToPreventPhpStanCallingMethods ()
{
    $a = SomeClass::class;

    SomeClass::class;

    bar()::FOO;
}
?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

function wrapToPreventPhpStanCallingMethods ()
{
    $a = SomeClass::class;

    bar();
}
?>
