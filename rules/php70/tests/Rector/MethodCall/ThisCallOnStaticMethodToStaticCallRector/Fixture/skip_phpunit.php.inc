<?php

namespace Rector\Php70\Tests\Rector\MethodCall\ThisCallOnStaticMethodToStaticCallRector\Fixture;

use PHPUnit\Framework\TestCase;

class SkipPhpunit
{
    public function testMe()
    {
        $this->assertTrue(True);
        $this->markTestSkipped('uups');
    }
}
