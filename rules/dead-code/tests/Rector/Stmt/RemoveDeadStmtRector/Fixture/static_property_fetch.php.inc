<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

function wrapToPreventPhpStanCallingMethods ()
{
    $a = SomeClass::$a;

    SomeClass::$a;

    bar()::$a;

    bar()::${baz()}::${foo()};
}
?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

function wrapToPreventPhpStanCallingMethods ()
{
    $a = SomeClass::$a;

    bar();

    bar();
    baz();
    foo();
}
?>
