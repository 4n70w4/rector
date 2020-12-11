<?php

namespace Rector\DeadCode\Tests\Rector\ClassMethod\RemoveDeadConstructorRector\Fixture;

class Skip
{
    public function __construct()
    {
        parent::__construct();
    }
}

class AnotherClass
{
    public function __construct()
    {
        $value = 5;
    }
}
