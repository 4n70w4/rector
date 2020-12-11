<?php

namespace Rector\Solid\Tests\Rector\Property\AddFalseDefaultToBoolPropertyRector\Fixture;

class SomeClass
{
    /**
     * @var bool
     */
    private $isDisabled;
}

?>
-----
<?php

namespace Rector\Solid\Tests\Rector\Property\AddFalseDefaultToBoolPropertyRector\Fixture;

class SomeClass
{
    /**
     * @var bool
     */
    private $isDisabled = false;
}

?>
