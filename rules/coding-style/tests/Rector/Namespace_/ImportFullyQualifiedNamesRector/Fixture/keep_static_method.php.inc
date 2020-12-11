<?php

declare(strict_types=1);

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

abstract class TokenGenerator
{
    public static function decode(string $token): Contract\Token
    {
        $parts = explode('|', (string) base64_decode($token, true));

        return Token::create($parts[0] ?? '', $parts[1] ?? '');
    }
}
