<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

use OldNamespace;

class SomeClass2
{
    public function someClass(Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture $argument)
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
