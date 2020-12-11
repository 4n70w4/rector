<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

use Tester\Assert;

function someStaticFunctions()
{
    Assert::true(10 == 5);
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

use Tester\Assert;

function someStaticFunctions()
{
    \PHPUnit\Framework\Assert::assertTrue(10 == 5);
}

?>
