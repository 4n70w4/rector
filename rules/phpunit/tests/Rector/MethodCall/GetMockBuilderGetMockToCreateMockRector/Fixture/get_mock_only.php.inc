<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class GetMockOnly extends \PHPUnit\Framework\TestCase
{
    public function test()
    {
        $applicationMock = $this->getMockBuilder('SomeClass')
            ->getMock();
    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class GetMockOnly extends \PHPUnit\Framework\TestCase
{
    public function test()
    {
        $applicationMock = $this->createMock('SomeClass');
    }
}

?>
