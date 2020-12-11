<?php

namespace Rector\Solid\Tests\Rector\Property\ChangeReadOnlyPropertyWithDefaultValueToConstantRector\Fixture;

class SkipMultipleProperties
{
    /**
     * @var string[]
     */
    private $moreMagic, $magicMethods = [
        '__toString',
        '__wakeup',
    ];
}
