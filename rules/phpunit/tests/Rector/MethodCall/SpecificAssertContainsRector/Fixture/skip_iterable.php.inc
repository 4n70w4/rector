<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

use PHPUnit\Framework\TestCase;

final class SkipIterable extends TestCase
{
    public function test(array $items)
    {
        $this->assertContains('foo', $items);
    }
}
