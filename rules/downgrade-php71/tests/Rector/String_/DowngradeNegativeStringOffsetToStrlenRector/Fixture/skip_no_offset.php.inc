<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SkipNoOffset
{
    public function run($var)
    {
        echo strpos('aabbcc', 'b');
    }
}

?>
