<?php

namespace Rector\Php70\Tests\Rector\StaticCall\StaticCallOnNonStaticToInstanceCallRector\Fixture;

class AddStaticToMethod
{
    private function __construct() // private constructor
    {
    }

    public function method()
    {
    }
}

class AddStaticToMethod2
{
    public function __construct(string $test) // constructor with parameter
    {
    }

    public function method()
    {
        echo "test2";
    }
}

class ClassWrapToPreventCodeRun
{
    public function run()
    {
        AddStaticToMethod::method();
        AddStaticToMethod2::method();
    }
}

?>
-----
<?php

namespace Rector\Php70\Tests\Rector\StaticCall\StaticCallOnNonStaticToInstanceCallRector\Fixture;

class AddStaticToMethod
{
    private function __construct() // private constructor
    {
    }

    public static function method()
    {
    }
}

class AddStaticToMethod2
{
    public function __construct(string $test) // constructor with parameter
    {
    }

    public static function method()
    {
        echo "test2";
    }
}

class ClassWrapToPreventCodeRun
{
    public function run()
    {
        AddStaticToMethod::method();
        AddStaticToMethod2::method();
    }
}

?>
