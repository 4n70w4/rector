<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

final class SetExplicit
{
    public function run(): void
    {
        $worksheet = new \PHPExcel_Worksheet();
        $cell = $worksheet->setCellValueExplicitByColumnAndRow('A1', 'value', 'bla', 'bla', true);
    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

final class SetExplicit
{
    public function run(): void
    {
        $worksheet = new \PHPExcel_Worksheet();
        $cell = $worksheet->getCellByColumnAndRow('A1', 'value')->setValueExplicit('bla', 'bla');
    }
}

?>
