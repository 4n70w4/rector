<?php

namespace Rector\PHPUnit\Tests\Rector\ClassMethod\AddDoesNotPerformAssertionToNonAssertingTestRector\Fixture;

class SkipExistingAnnotation
{
    /**
     * @doesNotPerformAssertions
     */
    public function testSomething(): void
    {
    }
}
