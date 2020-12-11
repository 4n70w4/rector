<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

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
