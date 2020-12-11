<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

final class StaticCallTest extends \PHPUnit\Framework\TestCase
{
    public function test()
    {
        $firstMock = self::getMock('SomeClass');
    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

final class StaticCallTest extends \PHPUnit\Framework\TestCase
{
    public function test()
    {
        $firstMock = self::createMock('SomeClass');
    }
}

?>
