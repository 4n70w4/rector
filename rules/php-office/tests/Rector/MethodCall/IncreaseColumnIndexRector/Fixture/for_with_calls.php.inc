<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

final class ForWithCalls
{
    public function run(): void
    {
        $max = 1000;
        $row = 5;
        $worksheet = new \PHPExcel_Worksheet();

        for ($column = 0; $column < $max; $column++) {
            $worksheet->setCellValueByColumnAndRow($column, $row, 'value ' . $column)->anotherCall();
        }
    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

final class ForWithCalls
{
    public function run(): void
    {
        $max = 1000;
        $row = 5;
        $worksheet = new \PHPExcel_Worksheet();

        for ($column = 1; $column < $max; $column++) {
            $worksheet->setCellValueByColumnAndRow($column, $row, 'value ' . $column)->anotherCall();
        }
    }
}

?>
