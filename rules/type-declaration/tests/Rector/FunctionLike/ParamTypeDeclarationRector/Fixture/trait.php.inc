<?php

namespace Rector\TypeDeclaration\Tests\Rector\FunctionLike\ParamTypeDeclarationRector\Fixture;

trait SomeTrait
{

}

class Trait
{
    /**
     * @param SomeTrait $param
     */
    function someFunction($param)
    {
    }
}

?>
