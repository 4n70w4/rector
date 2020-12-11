<?php

namespace Rector\Solid\Tests\Rector\Class_\ChangeReadOnlyVariableWithDefaultValueToConstantRector\Fixture;

class SkipReferenced
{
    public function run()
    {
        $value = [];
        $this->process($value);
    }

    private function process(array &$value)
    {
    }
}
