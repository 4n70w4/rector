<?php

namespace Rector\PhpOffice\Tests\Rector\StaticCall\ChangeChartRendererRector\Fixture;

final class SomeClass
{
    public function run(): void
    {
        \PHPExcel_Settings::setChartRenderer($rendererName, $rendererLibraryPath);
    }
}

?>
-----
<?php

namespace Rector\PhpOffice\Tests\Rector\StaticCall\ChangeChartRendererRector\Fixture;

final class SomeClass
{
    public function run(): void
    {
        \PHPExcel_Settings::setChartRenderer(\PhpOffice\PhpSpreadsheet\Chart\Renderer\JpGraph::class);
    }
}

?>
