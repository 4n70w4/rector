<?php

namespace Rector\MockistaToMockery\Tests\Rector\ClassMethod\MockistaMockToMockeryMockRector\Fixture;

use PHPUnit\Framework\TestCase;

class MethodsToRemove
{
    public function testSomething()
    {
        $mockUser = mock(User::class);
        $mockUser->freeze();
        $mockUser->assertExpectations();
    }
}

?>
-----
<?php

namespace Rector\MockistaToMockery\Tests\Rector\ClassMethod\MockistaMockToMockeryMockRector\Fixture;

use PHPUnit\Framework\TestCase;

class MethodsToRemove
{
    public function testSomething()
    {
        $mockUser = \Mockery::mock(User::class);
    }
}

?>
