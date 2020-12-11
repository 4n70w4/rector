<?php

namespace Rector\Phpunit\Tests\Rector\MethodCall\AssertSameTrueFalseToAssertTrueFalseRector\Fixture;

use PHPUnit\Framework\TestCase;

final class SomeTest extends TestCase
{
    public function test()
    {
        $value = (bool) mt_rand(0, 1);
        $this->assertSame(true, $value);
    }
}

?>
-----
<?php

namespace Rector\Phpunit\Tests\Rector\MethodCall\AssertSameTrueFalseToAssertTrueFalseRector\Fixture;

use PHPUnit\Framework\TestCase;

final class SomeTest extends TestCase
{
    public function test()
    {
        $value = (bool) mt_rand(0, 1);
        $this->assertTrue($value);
    }
}

?>
