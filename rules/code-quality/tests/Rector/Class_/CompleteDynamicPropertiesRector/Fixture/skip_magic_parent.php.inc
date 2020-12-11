<?php

namespace Rector\CodeQuality\Tests\Rector\Class_\CompleteDynamicPropertiesRector\Fixture;

use Rector\CodeQuality\Tests\Rector\Class_\CompleteDynamicPropertiesRector\Source\MagicParent;

class SkipMagicParent
{
    public function set()
    {
        $this->value = 5;
    }
}
