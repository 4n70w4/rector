<?php

namespace Rector\DeadCode\Tests\Rector\ClassMethod\RemoveUnusedParameterRector\Fixture;

class ParentRequired
{
    public function getIt($value, $value2)
    {
        $combo = $value + $value2;
    }

}

class ParentRequired extends ParentRequired
{
    public function getIt($value, $value2)
    {
        $this->value = $value;
    }
}
