<?php

namespace Rector\Php70\Tests\Rector\FuncCall\NonVariableToVariableOnFunctionCallRector\Fixture;

class StringyCalls
{
    public static function staticMethod(&$bar) {}
}

function stringyCalls()
{
    'reset'(bar());

    $functionName = 'reset';
    $functionName(bar());

    $methodName = StringyCalls::class.'::staticMethod';
    $methodName(bar());
}

?>
-----
<?php

namespace Rector\Php70\Tests\Rector\FuncCall\NonVariableToVariableOnFunctionCallRector\Fixture;

class StringyCalls
{
    public static function staticMethod(&$bar) {}
}

function stringyCalls()
{
    $bar = bar();
    'reset'($bar);

    $functionName = 'reset';
    $bar2 = bar();
    $functionName($bar2);

    $methodName = StringyCalls::class.'::staticMethod';
    $bar3 = bar();
    $methodName($bar3);
}

?>
