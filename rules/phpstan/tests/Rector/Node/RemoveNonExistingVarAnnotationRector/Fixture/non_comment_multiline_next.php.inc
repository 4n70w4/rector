<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class NonCommentMultiLineNext
{
    public function get($_some)
    {
        while ($_some = false) {
            /** @var array $_some */


        }
    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class NonCommentMultiLineNext
{
    public function get($_some)
    {
        while ($_some = false) {



        }
    }
}

?>
