<?php

namespace Rector\DeadCode\Tests\Rector\MethodCall\RemoveEmptyMethodCallRector\Fixture;

use Rector\DeadSkipUsingInterfaceode\Tests\Rector\MethodSkipUsingInterfaceall\RemoveEmptyMethodSkipUsingInterfaceallRector\Source\SomeInterface;

class SkipUsingInterface
{
    public function execute(SomeInterface $obj)
    {
        $obj->run();
    }
}

?>
