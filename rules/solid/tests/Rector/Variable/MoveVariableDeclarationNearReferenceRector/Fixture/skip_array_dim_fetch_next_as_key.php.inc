<?php

namespace Rector\Solid\Tests\Rector\Variable\MoveVariableDeclarationNearReferenceRector\Fixture;

class SkipArrayDimFetchNextAsKey
{
   private function foo($data, $aliasName)
    {
        $loweredAliasName = strtolower($aliasName);

        if (isset($data[$loweredAliasName])) {
            return true;
        }

        echo $loweredAliasName;
    }
}

?>
