<?php

namespace Rector\Phpunit\Tests\Rector\ClassMethod\AddDoesNotPerformAssertionToNonAssertingTestRector\Fixture;

use Rector\PHPUnit\Tests\Rector\ClassMethod\AddDoesNotPerformAssertionToNonAssertingTestRector\Source\AbstractClassWithStaticAssert;

class KeepWithParentMethodStaticAssert extends AbstractClassWithStaticAssert
{
    public function test()
    {
        $this->doAssertThis();
    }
}
