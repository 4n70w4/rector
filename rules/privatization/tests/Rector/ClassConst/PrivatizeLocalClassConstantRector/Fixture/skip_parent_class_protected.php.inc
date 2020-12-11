<?php

namespace Rector\Privatization\Tests\Rector\ClassConst\PrivatizeLocalClassConstantRector\Fixture;

use Rector\Privatization\Tests\Rector\ClassConst\PrivatizeLocalClassConstantRector\Source\SomeProtectedParentClass;

class SkipParentClassProtected
{
    protected const SOME_CONST = 'changed_value';
}
