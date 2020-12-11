<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

use PHPUnit\Framework\TestCase;

final class SkipAlready extends TestCase
{
    public function test()
    {
        $value = (bool) mt_rand(0, 1);
        $this->assertTrue($value);
    }
}
