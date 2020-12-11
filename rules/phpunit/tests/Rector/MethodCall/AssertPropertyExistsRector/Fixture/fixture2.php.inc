<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

final class MyTest2 extends \PHPUnit\Framework\TestCase
{
    public function test()
    {
        $response = new \Namespaced\Response();
        $this->assertFalse(property_exists($response, 'property'));
    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

final class MyTest2 extends \PHPUnit\Framework\TestCase
{
    public function test()
    {
        $response = new \Namespaced\Response();
        $this->assertObjectNotHasAttribute('property', $response);
    }
}

?>
