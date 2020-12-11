<?php

namespace Rector\TypeDeclaration\Tests\Rector\FunctionLike\ParamTypeDeclarationRector\Fixture;

class Variadic
{
    /**
     * @param mixed[] $values
     */
    public function someFunction(...$values)
    {
    }
}
