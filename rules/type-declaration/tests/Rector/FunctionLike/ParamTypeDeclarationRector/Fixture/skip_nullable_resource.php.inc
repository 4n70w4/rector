<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class NullableResourceTypes
{
    /**
     * @param resource|null $value
     */
    public function someFunction($value)
    {
    }
}
