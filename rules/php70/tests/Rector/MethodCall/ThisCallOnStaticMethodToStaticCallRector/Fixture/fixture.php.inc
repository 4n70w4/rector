<?php

namespace Rector\Php70\Tests\Rector\MethodCall\ThisCallOnStaticMethodToStaticCallRector\Fixture;

use Rector\Testing\Contract\RunnableInterface;

class Fixture
{
    public function speak()
    {
        return $this->whoami();
    }
    public static function whoami()
    {
        return 'parent';
    }
}

class SomeChild extends Fixture
{
    public static function whoami()
    {
        return 'child';
    }
}

class SomeRunnable implements RunnableInterface
{
    public function run()
    {
        $someChild = new SomeChild();
        return $someChild->speak();
    }
}

?>
-----
<?php

namespace Rector\Php70\Tests\Rector\MethodCall\ThisCallOnStaticMethodToStaticCallRector\Fixture;

use Rector\Testing\Contract\RunnableInterface;

class Fixture
{
    public function speak()
    {
        return static::whoami();
    }
    public static function whoami()
    {
        return 'parent';
    }
}

class SomeChild extends Fixture
{
    public static function whoami()
    {
        return 'child';
    }
}

class SomeRunnable implements RunnableInterface
{
    public function run()
    {
        $someChild = new SomeChild();
        return $someChild->speak();
    }
}

?>
