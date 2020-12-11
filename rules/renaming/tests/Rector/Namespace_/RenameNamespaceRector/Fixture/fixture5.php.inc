<?php

namespace Rector\Renaming\Tests\Rector\Namespace_\RenameNamespaceRector\Fixture;

class Fixture5
{
    public function someClass()
    {
        return new Fixture5;
    }
}

?>
-----
<?php

namespace Rector\Renaming\Tests\Rector\Namespace_\RenameNamespaceRector\Fixture;

class Fixture5
{
    public function someClass()
    {
        return new \Rector\Renaming\Tests\Rector\Namespace_\RenameNamespaceRector\Fixture\Fixture5;
    }
}

?>
