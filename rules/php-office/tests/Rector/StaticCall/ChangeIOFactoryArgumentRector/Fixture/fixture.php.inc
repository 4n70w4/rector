<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

final class SomeClass
{
    public function run(): void
    {
        $writer = \PHPExcel_IOFactory::createWriter('CSV');
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
        $writer = \PHPExcel_IOFactory::createWriter('Csv');
    }
}

?>
