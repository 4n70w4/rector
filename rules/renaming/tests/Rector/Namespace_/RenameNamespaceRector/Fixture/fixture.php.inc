<?php

namespace Rector\Renaming\Tests\Rector\Namespace_\RenameNamespaceRector\Fixture;

use OldNamespace;
use OldNamespace\AnotherSubNamespace;

class Fixture
{
    public function someClass()
    {
        $keepThis = new \OldNamespace;

        return new \OldNamespace\Fixture;
    }
}

?>
-----
<?php

namespace Rector\Renaming\Tests\Rector\Namespace_\RenameNamespaceRector\Fixture;

use NewNamespace;
use NewNamespace\AnotherSubNamespace;

class Fixture
{
    public function someClass()
    {
        $keepThis = new \OldNamespace;

        return new \NewNamespace\Fixture;
    }
}

?>
