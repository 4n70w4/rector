<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SkipNotStrpos
{
    public function run($var)
    {
        echo substr($var, -1);
    }
}

?>
