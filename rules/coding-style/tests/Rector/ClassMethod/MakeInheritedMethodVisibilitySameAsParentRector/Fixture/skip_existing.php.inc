<?php

namespace Rector\CodingStyle\Tests\Rector\ClassMethod\MakeInheritedMethodVisibilitySameAsParentRector\Fixture;

class SkipExisting
{
    protected function run()
    {
    }
}

class ParentClassWithProtectedMethod
{
    protected function run()
    {
    }
}
