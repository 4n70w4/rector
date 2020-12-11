<?php

namespace Rector\TypeDeclaration\Tests\Rector\FunctionLike\ParamTypeDeclarationRector\Fixture;

class VariadicTypes
{
    /**
     * @param mixed[] $values
     */
    public function someFunction(...$values)
    {
    }
}
