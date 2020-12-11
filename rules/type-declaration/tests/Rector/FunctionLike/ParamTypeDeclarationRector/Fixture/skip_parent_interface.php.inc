<?php

namespace Rector\TypeDeclaration\Tests\Rector\FunctionLike\ParamTypeDeclarationRector\Fixture;

use Rector\TypeDeclaration\Tests\Rector\FunctionLike\ParamTypeDeclarationRector\Source\ParentInterface;

class SkipParentInterface
{
    /**
     * @param string $value
     */
    public function __construct($value) {}
}
