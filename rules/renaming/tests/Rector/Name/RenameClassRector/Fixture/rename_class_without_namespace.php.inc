<?php

class MyOldClass
{
    /**
     * @return MyOldClass
     */
    public function createSelf(): MyOldClass
    {
        return new MyOldClass;
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
