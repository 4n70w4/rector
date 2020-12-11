<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

final class MyTest3 extends \PHPUnit_Framework_TestCase
{
    /**
     * @expectedException \Exception
     */
    public function testThrowExceptionWhenOperatorIsInvalid(): void
    {
    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

final class MyTest3 extends \PHPUnit_Framework_TestCase
{
    public function testThrowExceptionWhenOperatorIsInvalid(): void
    {
        $this->expectException(\Exception::class);
    }
}

?>
