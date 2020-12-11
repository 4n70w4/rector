<?php

namespace Rector\TypeDeclaration\Tests\Rector\FunctionLike\ParamTypeDeclarationRector\Fixture;

class SkipNullableResource
{
    /**
     * @param resource|null $value
     */
    public function someFunction($value)
    {
    }
}
