<?php

namespace Rector\Phpunit\Tests\Rector\MethodCall\CreateMockToCreateStubRector\Fixture;

class SkipNonPHPUnit
{
    public function run()
    {
        $stub = $this->createMock(\Exception::class);
    }
}
