<?php

namespace Rector\Phpunit\Tests\Rector\MethodCall\GetMockBuilderGetMockToCreateMockRector\Fixture;

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

namespace Rector\Phpunit\Tests\Rector\MethodCall\GetMockBuilderGetMockToCreateMockRector\Fixture;

class GetMockOnly extends \PHPUnit\Framework\TestCase
{
    public function test()
    {
        $applicationMock = $this->createMock('SomeClass');
    }
}

?>
