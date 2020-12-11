<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

use Mockery;
use PHPUnit\Framework\TestCase;

class JustMocksTest extends TestCase
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

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

use Mockery;
use PHPUnit\Framework\TestCase;

class JustMocksTest extends TestCase
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
