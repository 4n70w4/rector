<?php

namespace Rector\DeadCode\Tests\Rector\ClassMethod\RemoveDeadRecursiveClassMethodRector\Fixture;

interface SkipInterface
{
    public function process();
}

class SkipInterface
{
    public function process()
    {
        $this->process();
    }
}
