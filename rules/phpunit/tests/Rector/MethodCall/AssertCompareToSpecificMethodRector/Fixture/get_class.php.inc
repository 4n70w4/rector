<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

use stdClass;

final class GetClass extends \PHPUnit\Framework\TestCase
{
    public function test()
    {
        $something = new stdClass();
        $this->assertSame(get_class($something), 'stdClass');
        self::assertSame('stdClass', get_class($something));
    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

use stdClass;

final class GetClass extends \PHPUnit\Framework\TestCase
{
    public function test()
    {
        $something = new stdClass();
        $this->assertInstanceOf('stdClass', $something);
        self::assertInstanceOf('stdClass', $something);
    }
}

?>
