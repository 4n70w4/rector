<?php

namespace Rector\RemovingStatic\Tests\Rector\ClassMethod\LocallyCalledStaticMethodToNonStaticRector\Fixture;

use Rector\RemovingStatic\Tests\Rector\ClassMethod\LocallyCalledStaticMethodToNonStaticRector\Source\SomeParent;

class CaseWithParent
{
    private static function someStatic()
    {
    }

    public function run()
    {
        self::someStatic();
    }
}

?>
-----
<?php

namespace Rector\RemovingStatic\Tests\Rector\ClassMethod\LocallyCalledStaticMethodToNonStaticRector\Fixture;

use Rector\RemovingStatic\Tests\Rector\ClassMethod\LocallyCalledStaticMethodToNonStaticRector\Source\SomeParent;

class CaseWithParent
{
    private function someStatic()
    {
    }

    public function run()
    {
        $this->someStatic();
    }
}

?>
