<?php

namespace Rector\Renaming\Tests\Rector\Name\RenameClassRector\Fixture;

class MyClass
{
    /**
     * @return MyClass
     */
    public function createSelf(): MyClass
    {
        return new MyClass;
    }
}

?>
-----
<?php

namespace Rector\Renaming\Tests\Rector\Name\RenameClassRector\Fixture;

class MyNewClass
{
    /**
     * @return \Rector\Renaming\Tests\Rector\Name\RenameClassRector\Fixture\MyNewClass
     */
    public function createSelf(): \Rector\Renaming\Tests\Rector\Name\RenameClassRector\Fixture\MyNewClass
    {
        return new \Rector\Renaming\Tests\Rector\Name\RenameClassRector\Fixture\MyNewClass;
    }
}

?>
