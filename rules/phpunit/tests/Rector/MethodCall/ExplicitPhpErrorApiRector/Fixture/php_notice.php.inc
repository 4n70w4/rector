<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

use PHPUnit\Framework\TestCase;

final class RefactorNotice extends TestCase
{
    public function test()
    {
        $this->expectException(\PHPUnit\Framework\TestCase\Notice::class);
    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

use PHPUnit\Framework\TestCase;

final class RefactorNotice extends TestCase
{
    public function test()
    {
        $this->expectNotice();
    }
}

?>
