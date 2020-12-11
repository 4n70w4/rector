<?php

namespace Rector\Renaming\Tests\Rector\Namespace_\RenameNamespaceRector\Fixture;

use OldNamespace;

class Fixture2
{
    public function someClass(Rector\Renaming\Tests\Rector\Namespace_\RenameNamespaceRector\Fixture $argument)
    {
    }
}

?>
-----
<?php

namespace Rector\Renaming\Tests\Rector\Namespace_\RenameNamespaceRector\Fixture;

use NewNamespace;

class Fixture2
{
    public function someClass(\Rector\Renaming\Tests\Rector\Namespace_\RenameNamespaceRector\Fixture $argument)
    {
    }
}

?>
