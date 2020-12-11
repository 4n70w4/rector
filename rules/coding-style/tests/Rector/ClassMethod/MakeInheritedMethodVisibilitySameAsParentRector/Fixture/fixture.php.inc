<?php

namespace Rector\CodingStyle\Tests\Rector\ClassMethod\MakeInheritedMethodVisibilitySameAsParentRector\Fixture;

class Fixture
{
    public function run()
    {
    }
}

class ParentClass
{
    protected function run()
    {
    }
}

?>
-----
<?php

namespace Rector\CodingStyle\Tests\Rector\ClassMethod\MakeInheritedMethodVisibilitySameAsParentRector\Fixture;

class Fixture
{
    protected function run()
    {
    }
}

class ParentClass
{
    protected function run()
    {
    }
}

?>
