<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

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
