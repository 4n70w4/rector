<?php

namespace Rector\Renaming\Tests\Rector\Name\RenameClassRector\Fixture;

interface MyInterface
{
    /**
     * @return MyInterface
     */
    public function createSelf(): MyInterface;
}

?>
-----
<?php

namespace Rector\Renaming\Tests\Rector\Name\RenameClassRector\Fixture;

interface MyNewInterface
{
    /**
     * @return \Rector\Renaming\Tests\Rector\Name\RenameClassRector\Fixture\MyNewInterface
     */
    public function createSelf(): \Rector\Renaming\Tests\Rector\Name\RenameClassRector\Fixture\MyNewInterface;
}

?>
