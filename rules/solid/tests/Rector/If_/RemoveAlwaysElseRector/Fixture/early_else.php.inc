<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class EarlyElse
{
    public function run($value)
    {
        if ($value) {
            return 5;
        } else {
            return 10;
        }
    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class EarlyElse
{
    public function run($value)
    {
        if ($value) {
            return 5;
        }
        return 10;
    }
}

?>
