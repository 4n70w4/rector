<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

final class MyGetMockTest extends \PHPUnit\Framework\TestCase
{
    public function test()
    {
        $firstMock = $this->getMock('SomeClass');
    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

final class MyGetMockTest extends \PHPUnit\Framework\TestCase
{
    public function test()
    {
        $firstMock = $this->createMock('SomeClass');
    }
}

?>
