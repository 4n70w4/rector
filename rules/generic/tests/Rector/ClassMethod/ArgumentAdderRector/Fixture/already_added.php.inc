<?php

namespace Rector\Generic\Tests\Rector\ClassMethod\ArgumentAdderRector\Fixture;

use Rector\Generic\Tests\Rector\ClassMethod\ArgumentAdderRector\Source\SomeContainerBuilder;

class AlreadyAdded
{
    public function addCompilerPass($pass, $type, int $priority = 10)
    {
    }
}
