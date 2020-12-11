<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class MixedTypes
{
    /**
     * @param mixed|mixed[] $value
     */
    public function someFunction($value)
    {
    }
}
