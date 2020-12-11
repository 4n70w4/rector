<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

use PHPUnit\Framework\TestCase;

final class RefactorDeprecated extends TestCase
{
    public function test()
    {
        $this->expectException(\PHPUnit\Framework\TestCase\Deprecated::class);
    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

use PHPUnit\Framework\TestCase;

final class RefactorDeprecated extends TestCase
{
    public function test()
    {
        $this->expectDeprecation();
    }
}

?>
