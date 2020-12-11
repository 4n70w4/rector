<?php

namespace Rector\PHPUnit\Tests\Rector\ClassMethod\AddDoesNotPerformAssertionToNonAssertingTestRector\Fixture;

use Mockery;
use PHPUnit\Framework\TestCase;

class JustMocksTest
{
    public function test()
    {
        $mockNetteUser = Mockery::mock(User::class);
        $mockNetteUser->expects()->isAllowed('yes', 'vote');
    }
}

?>
-----
<?php

namespace Rector\PHPUnit\Tests\Rector\ClassMethod\AddDoesNotPerformAssertionToNonAssertingTestRector\Fixture;

use Mockery;
use PHPUnit\Framework\TestCase;

class JustMocksTest
{
    /**
     * @doesNotPerformAssertions
     */
    public function test()
    {
        $mockNetteUser = Mockery::mock(User::class);
        $mockNetteUser->expects()->isAllowed('yes', 'vote');
    }
}

?>
