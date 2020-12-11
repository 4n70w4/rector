<?php

namespace Rector\PHPUnit\Tests\Rector\ClassMethod\AddDoesNotPerformAssertionToNonAssertingTestRector\Fixture;

class KeepAssertInStaticCall
{
    public function test()
    {
        self::doElsewhere(5);
    }

    private static function doElsewhere($value)
    {
        if ($value) {
            self::assertNotNull($value);
        }
    }
}
