<?php

namespace Rector\Phpunit\Tests\Rector\MethodCall\GetMockBuilderGetMockToCreateMockRector\Fixture;

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

namespace Rector\Phpunit\Tests\Rector\MethodCall\GetMockBuilderGetMockToCreateMockRector\Fixture;

class SomeTest extends \PHPUnit\Framework\TestCase
{
    public function test()
    {
        $applicationMock = $this->createMock('SomeClass');
    }
}

?>
