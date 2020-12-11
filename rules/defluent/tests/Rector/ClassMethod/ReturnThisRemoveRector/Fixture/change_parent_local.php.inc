<?php

namespace Rector\Defluent\Tests\Rector\ClassMethod\ReturnThisRemoveRector\Fixture;

class ChangeParentLocal
{
    /**
     * @return self
     */
    public function someFunction()
    {
        foo();
        return $this;
    }
}

class SomeParentClassWithSameMethod
{
    /**
     * @return self
     */
    public function someFunction()
    {
        foo();
        return $this;
    }
}

?>
-----
<?php

namespace Rector\Defluent\Tests\Rector\ClassMethod\ReturnThisRemoveRector\Fixture;

class ChangeParentLocal
{
    public function someFunction(): void
    {
        foo();
    }
}

class SomeParentClassWithSameMethod
{
    public function someFunction(): void
    {
        foo();
    }
}

?>
