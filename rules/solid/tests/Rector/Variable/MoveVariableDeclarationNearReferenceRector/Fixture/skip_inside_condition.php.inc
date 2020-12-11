<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SkipInsideCondition
{
    function myMethod($node)
    {
        if (mktime() === false) {
            $node = 1;
        } else {
            echo $node;
        }
    }
}

?>
