<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SkipVariableAssign
{
    public static function createProbeItem($value, string $method, int $argumentPosition): string
    {
        $type = self::resolveValueTypeToString($value);
        $data = [$type, $method, $argumentPosition];

        return implode(';', $data) . PHP_EOL;
    }
}
