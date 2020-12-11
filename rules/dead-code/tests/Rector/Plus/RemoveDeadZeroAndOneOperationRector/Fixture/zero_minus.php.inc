<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class Assigns
{
    public function run(int $value)
    {
        $value = 0 - $value;
    }
}
?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class Assigns
{
    public function run(int $value)
    {
        $value = -$value;
    }
}
?>
