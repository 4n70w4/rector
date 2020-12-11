<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

function wrapToPreventPhpStanCallingMethods ($object)
{
    $a = clone $object;
    clone $object;
}
?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

function wrapToPreventPhpStanCallingMethods ($object)
{
    $a = clone $object;
}
?>
