<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

use OldNamespaceWith\OldSplitNamespace;

class SomeClass3
{
    public function someClass()
    {
        return new OldSplitNamespace\SomeClass3;
    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

use NewNamespaceWith\NewSplitNamespace;

class SomeClass3
{
    public function someClass()
    {
        return new \NewNamespaceWith\NewSplitNamespace\SomeClass3;
    }
}

?>
