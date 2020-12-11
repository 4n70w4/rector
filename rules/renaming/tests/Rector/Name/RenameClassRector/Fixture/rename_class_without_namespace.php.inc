<?php

class RenameClassWithoutNamespace
{
    /**
     * @return RenameClassWithoutNamespace
     */
    public function createSelf(): RenameClassWithoutNamespace
    {
        return new RenameClassWithoutNamespace;
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
