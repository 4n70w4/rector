<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class KeepAssertInStaticCall extends \PHPUnit\Framework\TestCase
{
    public function test()
    {
        self::doElsewhere(5);
    }

    private static function doElsewhere($value)
    {
        if ($value) {
            self::assertNotNull($value);
        }
    }
}
