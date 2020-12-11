<?php

namespace Rector\Solid\Tests\Rector\Variable\MoveVariableDeclarationNearReferenceRector\Fixture;

class SkipUsedInNextCatch
{
    function myMethod()
    {
        $position = getPosition();

        try {
            execute();
            echo $position;
        } catch (\Exception $e) {
            echo $position  + 1;
        } finally {
            echo $position  + 2;
        }
    }
}

?>
