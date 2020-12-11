<?php

namespace Rector\Defluent\Tests\Rector\ClassMethod\ReturnThisRemoveRector\Fixture;

class Fixture
{
    /**
     * @return Fixture
     */
    public function someFunction()
    {
        foo();
        return $this;
    }

    /**
     * @return Fixture
     */
    public function otherFunction()
    {
        bar();
        return $this;
    }
}

?>
-----
<?php

namespace Rector\Defluent\Tests\Rector\ClassMethod\ReturnThisRemoveRector\Fixture;

class Fixture
{
    public function someFunction(): void
    {
        foo();
    }

    public function otherFunction(): void
    {
        bar();
    }
}

?>
