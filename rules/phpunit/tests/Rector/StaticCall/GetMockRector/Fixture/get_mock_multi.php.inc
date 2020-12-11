<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

final class GetMockMultiTest extends \PHPUnit\Framework\TestCase
{
    public function test()
    {
        $firstMock = $this->getMock('LDUser', [], [], '', false);
    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

final class GetMockMultiTest extends \PHPUnit\Framework\TestCase
{
    public function test()
    {
        $firstMock = $this->createMock('LDUser');
    }
}

?>
