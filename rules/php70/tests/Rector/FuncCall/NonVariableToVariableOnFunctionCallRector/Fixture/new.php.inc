<?php

namespace Rector\Php70\Tests\Rector\FuncCall\NonVariableToVariableOnFunctionCallRector\Fixture;

class New
{
    reset(new \stdClass());
    reset(new Bar());
}

?>
-----
<?php

namespace Rector\Php70\Tests\Rector\FuncCall\NonVariableToVariableOnFunctionCallRector\Fixture;

class New
{
    $stdClass = new \stdClass();
    reset($stdClass);
    $bar = new Bar();
    reset($bar);
}

?>
