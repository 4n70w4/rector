<?php

namespace Rector\PhpOffice\Tests\Rector\MethodCall\ChangeConditionalGetConditionRector\Fixture;

final class SomeClass
{
    public function run(): void
    {
        $conditional = new \PHPExcel_Style_Conditional;
        $someCondition = $conditional->getCondition();
    }
}

?>
-----
<?php

namespace Rector\PhpOffice\Tests\Rector\MethodCall\ChangeConditionalGetConditionRector\Fixture;

final class SomeClass
{
    public function run(): void
    {
        $conditional = new \PHPExcel_Style_Conditional;
        $someCondition = $conditional->getConditions()[0] ?? '';
    }
}

?>
