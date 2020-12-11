<?php

namespace Rector\CodeQuality\Tests\Rector\Class_\CompleteDynamicPropertiesRector\Fixture;

class SkipTraitUsed
{
    use PropertyInjection;

    public function set()
    {
        $this->value = 5;
    }
}

trait PropertyInjection
{
    private $value;
}
