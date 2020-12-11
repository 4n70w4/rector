<?php

namespace Rector\DeadCode\Tests\Rector\MethodCall\RemoveEmptyMethodCallRector\Fixture;

use Rector\DeadCode\Tests\Rector\MethodCall\RemoveEmptyMethodCallRector\Source\EmptyMethod;

class SkipCallFromPropertyFetch
{
    public $obj;

    public function __construct(EmptyMethod $obj)
    {
        $this->obj = $obj;
    }
}

class A extends SkipCallFromPropertyFetch
{
    public function execute()
    {
        $this->obj->run();
    }
}

?>
