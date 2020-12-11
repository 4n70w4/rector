<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

final class SkipStaticCall extends \PHPUnit\Framework\TestCase
{
    public function test()
    {
        self::assertFalse(SomeClass::someMethod());
    }
}
