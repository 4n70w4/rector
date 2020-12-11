<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

use PHPUnit\Framework\TestCase;

final class NoChangeOnStrings extends TestCase
{
    public function test()
    {
        $this->assertContains('foo', 'foo bar', 'message', false, false);
        $this->assertNotContains('foo', 'foo bar', 'message', false, false);
    }
}
