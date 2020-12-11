<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class KeepAssert extends \PHPUnit\Framework\TestCase
{
    public function test()
    {
        $nothing = 5;
        $this->assertNotNull(5);
    }

    public function testStatic()
    {
        $nothing = 5;
        self::assertNotNull(5);
    }
}
