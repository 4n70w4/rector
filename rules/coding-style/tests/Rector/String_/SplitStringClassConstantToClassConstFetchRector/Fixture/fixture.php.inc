<?php

namespace Rector\CodingStyle\Tests\Rector\String_\SplitStringClassConstantToClassConstFetchRector\Fixture;

class Fixture
{
    const HI = true;
}

class AnotherClass
{
    public function get()
    {
        return 'Rector\CodingStyle\Tests\Rector\String_\SplitStringClassConstantToClassConstFetchRector\Fixture\Fixture::HI';
    }
}

?>
-----
<?php

namespace Rector\CodingStyle\Tests\Rector\String_\SplitStringClassConstantToClassConstFetchRector\Fixture;

class Fixture
{
    const HI = true;
}

class AnotherClass
{
    public function get()
    {
        return \Rector\CodingStyle\Tests\Rector\String_\SplitStringClassConstantToClassConstFetchRector\Fixture\Fixture::class . '::HI';
    }
}

?>
