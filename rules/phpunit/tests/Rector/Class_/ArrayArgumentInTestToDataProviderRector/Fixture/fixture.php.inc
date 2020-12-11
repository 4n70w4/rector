<?php

namespace Rector\PHPUnit\Tests\Rector\Class_\ArrayArgumentInTestToDataProviderRector\Fixture;

class Fixture
{
    public function test()
    {
        $this->doTestMultiple([1, 2, 3]);
    }
}

?>
-----
<?php

namespace Rector\PHPUnit\Tests\Rector\Class_\ArrayArgumentInTestToDataProviderRector\Fixture;

class Fixture
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
