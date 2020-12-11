<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SkipUsedInNextElse
{
    function myMethod()
    {
        $position = getPosition();

        if (rand(0, 1) === 1) {
            echo $position;
        } elseif (rand(0, 1) === 0) {
            echo $position + 1;
        } else {
            echo $position + 2;
        }
    }
}

?>
