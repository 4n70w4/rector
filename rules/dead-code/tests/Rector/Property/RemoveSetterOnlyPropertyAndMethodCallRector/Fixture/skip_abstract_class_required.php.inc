<?php

namespace Rector\DeadCode\Tests\Rector\Property\RemoveSetterOnlyPropertyAndMethodCallRector\Fixture;

class SkipAbstractClassRequired
{
    private $name;
    public function setName(string $name): void
    {
        $this->name = $name;
    }
}

abstract class AbstractClassRequiring
{
    protected abstract function setName(string $name);
}
