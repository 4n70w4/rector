<?php

namespace Rector\Solid\Tests\Rector\If_\RemoveAlwaysElseRector\Fixture;

class SomeClass
{
    public function run()
    {
        if ($cond1) {

        } else {
            foo();
            return 'bar';
        }
    }
}

?>
