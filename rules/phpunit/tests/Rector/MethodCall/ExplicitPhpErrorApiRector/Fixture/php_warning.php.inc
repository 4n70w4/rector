<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

use PHPUnit\Framework\TestCase;

final class RefactorWarning extends TestCase
{
    public function test()
    {
        $this->expectException(\PHPUnit\Framework\TestCase\Warning::class);
    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

use PHPUnit\Framework\TestCase;

final class RefactorWarning extends TestCase
{
    public function test()
    {
        $this->expectWarning();
    }
}

?>
