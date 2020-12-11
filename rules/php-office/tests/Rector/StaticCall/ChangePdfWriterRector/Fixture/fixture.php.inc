<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

final class SomeClass
{
    public function run(): void
    {
        \PHPExcel_Settings::setPdfRendererName(PHPExcel_Settings::PDF_RENDERER_MPDF);
        \PHPExcel_Settings::setPdfRenderer($somePath);
        $writer = \PHPExcel_IOFactory::createWriter($spreadsheet, 'PDF');
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
        $writer = new \PhpOffice\PhpSpreadsheet\Writer\Pdf\Mpdf($spreadsheet);
    }
}

?>
