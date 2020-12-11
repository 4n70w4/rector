<?php

namespace Rector\TypeDeclaration\Tests\Rector\FunctionLike\ParamTypeDeclarationRector\Fixture;

trait SomeTrait
{

}

class SomeClass
{
    /**
     * @param SomeTrait $param
     */
    function someFunction($param)
    {
    }
}

?>
