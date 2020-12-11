<?php

namespace Rector\Solid\Tests\Rector\Class_\ChangeReadOnlyVariableWithDefaultValueToConstantRector\Fixture;

class SkipDoubleAssign
{
    protected function run()
    {
        $a = $b = $c = $d = '';
    }
}
