<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SomeTest extends \PHPUnit\Framework\TestCase
{
    /**
     * testGetTranslatedModelField method
     *
     * @return void
     */
    public function testGetTranslatedModelField()
    {
    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SomeTest extends \PHPUnit\Framework\TestCase
{
}

?>
