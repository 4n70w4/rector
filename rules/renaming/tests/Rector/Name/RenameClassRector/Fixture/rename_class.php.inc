<?php

namespace Rector\Renaming\Tests\Rector\Name\RenameClassRector\Fixture;

class RenameClass
{
    /**
     * @return RenameClass
     */
    public function createSelf(): RenameClass
    {
        return new RenameClass;
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
