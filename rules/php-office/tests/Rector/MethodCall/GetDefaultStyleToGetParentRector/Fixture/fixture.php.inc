<?php

namespace Rector\PhpOffice\Tests\Rector\MethodCall\GetDefaultStyleToGetParentRector\Fixture;

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

namespace Rector\PhpOffice\Tests\Rector\MethodCall\GetDefaultStyleToGetParentRector\Fixture;

class SomeClass
{
    public function run()
    {
        $worksheet = new \PHPExcel_Worksheet();
        $worksheet->getParent()->getDefaultStyle();
    }
}

?>
