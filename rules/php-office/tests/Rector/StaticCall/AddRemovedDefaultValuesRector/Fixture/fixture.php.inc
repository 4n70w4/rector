<?php

namespace Rector\PhpOffice\Tests\Rector\StaticCall\AddRemovedDefaultValuesRector\Fixture;

final class SomeClass
{
    public function run(): void
    {
        $logger = new \PHPExcel_CalcEngine_Logger;
        $logger->setWriteDebugLog();
    }
}

?>
-----
<?php

namespace Rector\PhpOffice\Tests\Rector\StaticCall\AddRemovedDefaultValuesRector\Fixture;

final class SomeClass
{
    public function run(): void
    {
        $logger = new \PHPExcel_CalcEngine_Logger;
        $logger->setWriteDebugLog(false);
    }
}

?>
