<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

final class MyContainsStrposTest extends \PHPUnit\Framework\TestCase
{
    public function test()
    {
        $this->assertNotFalse(strpos($node, 'foo'));
        $this->assertFalse(stripos($node, 'foo'), 'message');
    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

final class MyContainsStrposTest extends \PHPUnit\Framework\TestCase
{
    public function test()
    {
        $this->assertContains('foo', $node);
        $this->assertNotContains('foo', $node, 'message');
    }
}

?>
