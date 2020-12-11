<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SomeServiceTest extends \PHPUnit\Framework\TestCase
{
    public function test()
    {
        $this->doTestMultiple([1, 2, 3]);
    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SomeServiceTest extends \PHPUnit\Framework\TestCase
{
    /**
     * @dataProvider provideDataForTest()
     */
    public function test(int $variable)
    {
        $this->doTestSingle($variable);
    }
    public function provideDataForTest(): \Iterator
    {
        yield [1];
        yield [2];
        yield [3];
    }
}

?>
