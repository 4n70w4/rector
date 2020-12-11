<?php

namespace Rector\Phpunit\Tests\Rector\ClassMethod\AddDoesNotPerformAssertionToNonAssertingTestRector\Fixture;

class KeepNonPublic extends \PHPUnit\Framework\TestCase
{
    protected function testDelegated()
    {
    }
}
