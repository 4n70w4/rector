<?php

namespace Rector\DeadCode\Tests\Rector\ClassConst\RemoveUnusedClassConstantRector\Fixture;

use Rector\DeadCode\Tests\Rector\ClassConst\RemoveUnusedClassConstantRector\Source\AbstractEnum;

class SkipEnum
{
    public const ENUM_MAGIC = 'yes';
}
