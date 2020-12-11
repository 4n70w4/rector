<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class KnownFloat
{
    public function getFloating()
    {
        if (true) {
            return 5.2;
        }

        return 5.3;
    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class KnownFloat
{
    public function getFloating(): float
    {
        if (true) {
            return 5.2;
        }

        return 5.3;
    }
}

?>
