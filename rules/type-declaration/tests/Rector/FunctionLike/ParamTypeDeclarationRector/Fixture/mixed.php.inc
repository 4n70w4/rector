<?php

namespace Rector\TypeDeclaration\Tests\Rector\FunctionLike\ParamTypeDeclarationRector\Fixture;

class MixedTypes
{
    /**
     * @param mixed|mixed[] $value
     */
    public function someFunction($value)
    {
    }
}
