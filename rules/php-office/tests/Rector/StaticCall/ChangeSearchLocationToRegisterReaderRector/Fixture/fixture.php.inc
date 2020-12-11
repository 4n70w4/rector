<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

final class SomeClass
{
    public function run(): void
    {
        \PHPExcel_IOFactory::addSearchLocation($type, $location, $classname);
    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

final class SomeClass
{
    public function run(): void
    {
        \PhpOffice\PhpSpreadsheet\IOFactory::registerReader($type, $classname);
    }
}

?>
