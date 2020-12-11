<?php

namespace Rector\CodingStyle\Tests\Rector\ClassMethod\MakeInheritedMethodVisibilitySameAsParentRector\Fixture;

class Private
{
    public function run()
    {
    }
}

class ParentClassWithPrivateMethod
{
    private function run()
    {
    }
}

?>
-----
<?php

namespace Rector\CodingStyle\Tests\Rector\ClassMethod\MakeInheritedMethodVisibilitySameAsParentRector\Fixture;

class Private
{
    private function run()
    {
    }
}

class ParentClassWithPrivateMethod
{
    private function run()
    {
    }
}

?>
