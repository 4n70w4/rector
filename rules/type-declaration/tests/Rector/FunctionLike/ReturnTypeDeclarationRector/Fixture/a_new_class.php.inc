<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class ANewClass
{
    public function getObject()
    {
        return new class() {};
    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class ANewClass
{
    public function getObject(): object
    {
        return new class() {};
    }
}

?>
