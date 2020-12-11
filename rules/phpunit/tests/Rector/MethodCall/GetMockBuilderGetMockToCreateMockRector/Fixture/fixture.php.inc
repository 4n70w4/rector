<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SomeTest extends \PHPUnit\Framework\TestCase
{
    public function test()
    {
        $applicationMock = $this->getMockBuilder('SomeClass')
           ->disableOriginalConstructor()
           ->getMock();
    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SomeTest extends \PHPUnit\Framework\TestCase
{
    public function test()
    {
        $applicationMock = $this->createMock('SomeClass');
    }
}

?>
