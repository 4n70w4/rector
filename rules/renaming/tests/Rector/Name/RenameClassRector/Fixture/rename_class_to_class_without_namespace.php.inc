<?php

namespace Rector\Renaming\Tests\Rector\Name\RenameClassRector\Fixture;

class RenameClassToClassWithoutNamespace
{
    /**
     * @return RenameClassToClassWithoutNamespace
     */
    public function createSelf(): RenameClassToClassWithoutNamespace
    {
        return new RenameClassToClassWithoutNamespace;
    }
}

?>
-----
<?php

class MyNewClassWithoutNamespace
{
    /**
     * @return \MyNewClassWithoutNamespace
     */
    public function createSelf(): \MyNewClassWithoutNamespace
    {
        return new \MyNewClassWithoutNamespace;
    }
}

?>
