<?php

namespace Rector\CodeQuality\Tests\Rector\Class_\CompleteDynamicPropertiesRector\Fixture;

class SkipParentProperty
{
    public function set()
    {
        $this->value = 5;
    }
}

class SomeParentClassWithProperty
{
    public $value;
}
