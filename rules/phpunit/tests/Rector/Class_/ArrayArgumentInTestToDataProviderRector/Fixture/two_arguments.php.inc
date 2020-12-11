<?php

namespace Rector\PHPUnit\Tests\Rector\Class_\ArrayArgumentInTestToDataProviderRector\Fixture;

class TwoArguments
{
    public function test()
    {
        $this->doTestMultiple([['before', 'after']]);
    }
}

?>
-----
<?php

namespace Rector\PHPUnit\Tests\Rector\Class_\ArrayArgumentInTestToDataProviderRector\Fixture;

class TwoArguments
{
    /**
     * @dataProvider provideDataForTest()
     */
    public function test(string $variable, string $variable2)
    {
        $this->doTestSingle($variable, $variable2);
    }
    public function provideDataForTest(): \Iterator
    {
        yield [['before', 'after']];
    }
}

?>
