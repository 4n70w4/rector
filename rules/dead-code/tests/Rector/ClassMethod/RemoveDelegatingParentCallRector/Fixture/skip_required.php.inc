<?php

namespace Rector\DeadCode\Tests\Rector\ClassMethod\RemoveDelegatingParentCallRector\Fixture;

use Symfony\Contracts\EventDispatcher\EventDispatcherInterface;

class SkipRequired
{
    /**
     * @required
     */
    public function setEventDispatcher(EventDispatcherInterface $eventDispatcher)
    {
        parent::setEventDispatcher($eventDispatcher);
    }
}

class ParentClassWithoutRequired
{
    public function setEventDispatcher(EventDispatcherInterface $eventDispatcher)
    {
    }
}
