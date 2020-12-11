<?php

namespace Rector\TypeDeclaration\Tests\Rector\ClassMethod\AddReturnTypeDeclarationRector\Fixture;

use Rector\TypeDeclaration\Tests\Rector\ClassMethod\AddReturnTypeDeclarationRector\Source\FirstChildPHPUnitTestCase;

class ExtendedParentUpAndDown
{
    public function tearDown()
    {
    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\ClassMethod\AddReturnTypeDeclarationRector\Fixture;

use Rector\TypeDeclaration\Tests\Rector\ClassMethod\AddReturnTypeDeclarationRector\Source\FirstChildPHPUnitTestCase;

class ExtendedParentUpAndDown
{
    public function tearDown(): void
    {
    }
}

?>
