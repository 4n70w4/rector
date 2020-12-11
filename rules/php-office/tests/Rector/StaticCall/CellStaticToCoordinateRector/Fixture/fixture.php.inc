<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SomeClass
{
    public function run()
    {
        \PHPExcel_Cell::stringFromColumnIndex();
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
        \PhpOffice\PhpSpreadsheet\Cell\Coordinate::stringFromColumnIndex();
    }
}

?>
