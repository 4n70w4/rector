<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

final class SkipEndFunction
{
    private $values = ['1.2'];

    public function run($value): string
    {
        return $value ?? \end($this->values);
    }
}
