<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

final class MyTest extends \PHPUnit_Framework_TestCase
{
    /**
     * @expectedException \FooException
     */
    public function test()
    {
        // some code

    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

final class MyTest extends \PHPUnit_Framework_TestCase
{
    public function test()
    {
        $this->expectException('FooException');
        // some code

    }
}

?>
