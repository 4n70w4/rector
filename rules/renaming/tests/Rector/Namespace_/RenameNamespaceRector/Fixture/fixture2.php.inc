<?php

namespace Rector\Renaming\Tests\Rector\Namespace_\RenameNamespaceRector\Fixture;

use OldNamespace;

class SomeClass2
{
    public function someClass(Rector\Renaming\Tests\Rector\Namespace_\RenameNamespaceRector\Fixture $argument)
    {
    }
}

?>
-----
<?php

namespace NewNamespace\SubNamespace;

use NewNamespace;

class SomeClass2
{
    public function someClass(\NewNamespace\SubNamespace $argument)
    {
    }
}

?>
