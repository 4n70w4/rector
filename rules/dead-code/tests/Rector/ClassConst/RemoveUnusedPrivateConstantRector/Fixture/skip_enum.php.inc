<?php

namespace Rector\DeadCode\Tests\Rector\ClassConst\RemoveUnusedPrivateConstantRector\Fixture;

use Rector\DeadCode\Tests\Rector\ClassConst\RemoveUnusedPrivateConstantRector\Source\AbstractEnum;

class SkipEnum
{
    private const ENUM_MAGIC = 'yes';
}
