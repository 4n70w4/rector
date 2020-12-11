<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

final class KeepPrivateConstructor
{
    private function __construct()
    {

    }

    public static function someNamedConstructor(): self
    {
        return new self();
    }
}
