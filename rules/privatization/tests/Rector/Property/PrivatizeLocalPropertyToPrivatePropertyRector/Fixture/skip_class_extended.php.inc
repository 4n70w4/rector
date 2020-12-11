<?php

namespace Rector\Privatization\Tests\Rector\Property\PrivatizeLocalPropertyToPrivatePropertyRector\Fixture;

class SkipClassExtended
{
    /**
     * @api
     */
    public function stop()
    {
        $this->value;
    }
}

abstract class AbstractParentClass
{
    public $value;
}
