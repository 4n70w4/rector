<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

use PHPUnit\Framework\TestCase;

final class Fixture2Test extends TestCase
{
    public function testSomething(object $object, string $method, array $input, string $expected): void
    {
        static::assertSame($expected, $object::$method($input));
    }
}
