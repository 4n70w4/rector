<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

use PHPUnit_SpecialClass;

class SomeTest
{
    public function create()
    {
        $specialClass = new PHPUnit_SpecialClass;
    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

use PHPUnit\SpecialClass;

class SomeTest
{
    public function create()
    {
        $specialClass = new \PHPUnit\SpecialClass;
    }
}

?>
