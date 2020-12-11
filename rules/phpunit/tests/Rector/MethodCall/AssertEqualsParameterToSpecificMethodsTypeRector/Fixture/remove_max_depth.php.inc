<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

use PHPUnit\Framework\TestCase;

final class RemoveMaxDepth extends TestCase
{
    public function test()
    {
        $value = 'value';
        $this->assertEquals('string', $value, 'message', 0.0, 20);
    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

use PHPUnit\Framework\TestCase;

final class RemoveMaxDepth extends TestCase
{
    public function test()
    {
        $value = 'value';
        $this->assertEquals('string', $value, 'message');
    }
}

?>
