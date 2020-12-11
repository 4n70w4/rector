<?php

namespace Rector\Phpunit\Tests\Rector\ClassMethod\AddDoesNotPerformAssertionToNonAssertingTestRector\Fixture;

class SomeClass extends \PHPUnit\Framework\TestCase
{
    public function test()
    {
        $nothing = 5;
    }
}

?>
-----
<?php

namespace Rector\Phpunit\Tests\Rector\ClassMethod\AddDoesNotPerformAssertionToNonAssertingTestRector\Fixture;

class SomeClass extends \PHPUnit\Framework\TestCase
{
    /**
     * @doesNotPerformAssertions
     */
    public function test()
    {
        $nothing = 5;
    }
}

?>
