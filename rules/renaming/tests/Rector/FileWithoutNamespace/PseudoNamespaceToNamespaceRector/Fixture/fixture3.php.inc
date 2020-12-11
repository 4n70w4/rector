<?php

class Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture_Abc
{
    public function run()
    {
        return 1;
    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class Abc
{
    public function run()
    {
        return 1;
    }
}

?>
