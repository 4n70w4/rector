<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

function myFunction($param = false)
{
}
/**
 * @param string $param
 */
function myOtherFunction($param)
{
}
?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

function myFunction($param = false)
{
}
/**
 * @param string $param
 */
function myOtherFunction(string $param)
{
}
?>
