<?php

namespace Rector\Phpunit\Tests\Rector\ClassMethod\AddDoesNotPerformAssertionToNonAssertingTestRector\Fixture;

class SkipExistingAnnotation extends \PHPUnit\Framework\TestCase
{
    /**
     * @doesNotPerformAssertions
     */
    public function testSomething(): void
    {
    }
}
