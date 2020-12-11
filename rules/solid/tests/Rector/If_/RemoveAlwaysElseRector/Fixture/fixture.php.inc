<?php

namespace Rector\Solid\Tests\Rector\If_\RemoveAlwaysElseRector\Fixture;

class SomeClass
{
    public function run($value)
    {
        if ($value) {
            throw new \InvalidStateException;
        } else {
            return 10;
        }
    }
}

?>
-----
<?php

namespace Rector\Solid\Tests\Rector\If_\RemoveAlwaysElseRector\Fixture;

class SomeClass
{
    public function run($value)
    {
        if ($value) {
            throw new \InvalidStateException;
        }
        return 10;
    }
}

?>
