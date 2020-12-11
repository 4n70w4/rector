<?php

namespace Rector\DeadCode\Tests\Rector\ClassMethod\RemoveEmptyClassMethodRector\Fixture;

final class WithParent extends WithParent
{
    public function run()
    {
    }

    public function trample()
    {
    }
}

class WithParent
{
    public function run()
    {
        echo 'hi';
    }
}

?>
-----
<?php

namespace Rector\DeadCode\Tests\Rector\ClassMethod\RemoveEmptyClassMethodRector\Fixture;

final class WithParent extends WithParent
{
    public function run()
    {
    }
}

class WithParent
{
    public function run()
    {
        echo 'hi';
    }
}

?>
