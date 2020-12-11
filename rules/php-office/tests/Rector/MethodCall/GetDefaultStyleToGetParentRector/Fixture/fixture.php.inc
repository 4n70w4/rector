<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SomeClass
{
    public function run()
    {
        $worksheet = new \PHPExcel_Worksheet();
        $worksheet->getDefaultStyle();
    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SomeClass
{
    public function run()
    {
        $worksheet = new \PHPExcel_Worksheet();
        $worksheet->getParent()->getDefaultStyle();
    }
}

?>
