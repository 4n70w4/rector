<?php

namespace Rector\Php70\Tests\Rector\StaticCall\StaticCallOnNonStaticToInstanceCallRector\Fixture;

class Fixture
{
    public function doWork()
    {
    }
}

class Another
{
    public function run()
    {
        return Fixture::doWork(1);
    }
}

?>
-----
<?php

namespace Rector\Php70\Tests\Rector\StaticCall\StaticCallOnNonStaticToInstanceCallRector\Fixture;

class Fixture
{
    public function doWork()
    {
    }
}

class Another
{
    public function run()
    {
        return (new Fixture())->doWork(1);
    }
}

?>
