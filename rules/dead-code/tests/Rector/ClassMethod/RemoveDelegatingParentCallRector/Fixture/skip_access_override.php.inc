<?php

namespace Rector\DeadCode\Tests\Rector\ClassMethod\RemoveDelegatingParentCallRector\Fixture;

class SkipAccessOverride
{
    public function getName()
    {
        return parent::getName();
    }
}

class ParentClassWithProtected
{
    protected function getName()
    {
        return 'hello';
    }
}
