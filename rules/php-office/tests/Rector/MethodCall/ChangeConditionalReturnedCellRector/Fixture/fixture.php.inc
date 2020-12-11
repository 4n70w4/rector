<?php

namespace Rector\PhpOffice\Tests\Rector\MethodCall\ChangeConditionalReturnedCellRector\Fixture;

final class SomeClass
{
    public function run(): void
    {
        $worksheet = new \PHPExcel_Worksheet();
        $cell = $worksheet->setCellValue('A1', 'value', true);
    }
}

?>
-----
<?php

namespace Rector\PhpOffice\Tests\Rector\MethodCall\ChangeConditionalReturnedCellRector\Fixture;

final class SomeClass
{
    public function run(): void
    {
        $worksheet = new \PHPExcel_Worksheet();
        $cell = $worksheet->getCell('A1')->setValue('value');
    }
}

?>
