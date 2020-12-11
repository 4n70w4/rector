<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

function ternary($value)
{
    $value ? $a = 1 : $a = 0;
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

function ternary($value)
{
    $a = $value ? 1 : 0;
}

?>
