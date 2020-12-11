<?php

namespace Rector\Renaming\Tests\Rector\Namespace_\RenameNamespaceRector\Fixture;

use OldNamespaceWith\OldSplitNamespace;

class Fixture3
{
    public function someClass()
    {
        return new OldSplitNamespace\Fixture3;
    }
}

?>
-----
<?php

namespace Rector\Renaming\Tests\Rector\Namespace_\RenameNamespaceRector\Fixture;

use NewNamespaceWith\NewSplitNamespace;

class Fixture3
{
    public function someClass()
    {
        return new \NewNamespaceWith\NewSplitNamespace\Fixture3;
    }
}

?>
