<?php

namespace Rector\DeadCode\Tests\Rector\Class_\RemoveUnusedClassesRector\Fixture;

use Rector\DeadCode\Tests\Rector\Class_\RemoveUnusedClassesRector\Source\SomeInterface;

class SkipUsedNew
{
    public function run()
    {
        $values = new SomeClassToBeCreated();
    }
}

class SomeClassToBeCreated
{

}
