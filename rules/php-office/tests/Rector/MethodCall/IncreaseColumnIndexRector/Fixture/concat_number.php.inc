<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

final class PlusNumber
{
    public function run(): void
    {
        $worksheet = new \PHPExcel_Worksheet();

        $number = 55;
        $worksheet->setCellValueByColumnAndRow($number + 3, 3, '1150');
    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

final class PlusNumber
{
    public function run(): void
    {
        $worksheet = new \PHPExcel_Worksheet();

        $number = 55;
        $worksheet->setCellValueByColumnAndRow($number + 4, 3, '1150');
    }
}

?>
