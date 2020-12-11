<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class VariadicTypes
{
    /**
     * @param mixed[] $values
     */
    public function someFunction(...$values)
    {
    }
}
