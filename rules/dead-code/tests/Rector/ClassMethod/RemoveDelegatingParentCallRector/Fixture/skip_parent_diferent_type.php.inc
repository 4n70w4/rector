<?php

namespace Rector\DeadCode\Tests\Rector\ClassMethod\RemoveDelegatingParentCallRector\Fixture;

use Rector\DeadCode\Tests\Rector\ClassMethod\RemoveDelegatingParentCallRector\Source\ChildOfToBeImplementedInterface;
use Rector\DeadCode\Tests\Rector\ClassMethod\RemoveDelegatingParentCallRector\Source\ParentClassWithInterfaceType;

class SkipParentDiferentType
{
    public function __construct(ChildOfToBeImplementedInterface $toBeImplemented)
    {
        parent::__construct($toBeImplemented);
    }
}
