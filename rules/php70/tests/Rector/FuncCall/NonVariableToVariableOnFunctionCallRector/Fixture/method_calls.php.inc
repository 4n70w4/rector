<?php

namespace Rector\Php70\Tests\Rector\FuncCall\NonVariableToVariableOnFunctionCallRector\Fixture;

class MethodCalls
{
    public function bar(&$bar) {}
}

class AClass
{
    public static function staticMethod(&$bar) {}

    public function baz(&$bar) {}

    public function child(): MethodCalls
    {
        return new MethodCalls();
    }
}

function methodCalls()
{
    AClass::staticMethod(bar());
    $aClass = new AClass();
    $aClass->baz(baz());
    $aClass->child()->bar(bar());
}

?>
-----
<?php

namespace Rector\Php70\Tests\Rector\FuncCall\NonVariableToVariableOnFunctionCallRector\Fixture;

class MethodCalls
{
    public function bar(&$bar) {}
}

class AClass
{
    public static function staticMethod(&$bar) {}

    public function baz(&$bar) {}

    public function child(): MethodCalls
    {
        return new MethodCalls();
    }
}

function methodCalls()
{
    $bar = bar();
    AClass::staticMethod($bar);
    $aClass = new AClass();
    $baz = baz();
    $aClass->baz($baz);
    $bar2 = bar();
    $aClass->child()->bar($bar2);
}

?>
