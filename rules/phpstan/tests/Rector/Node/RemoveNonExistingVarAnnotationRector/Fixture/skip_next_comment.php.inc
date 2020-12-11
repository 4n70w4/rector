<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SkipNextComment
{
    public function get($_some)
    {
        while ($_some = false) {
            /** @var array $_some */
            // some comment
        }
    }
}

?>
