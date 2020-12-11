<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class IfCase
{
    public function run()
    {
        /** @var ClassMethod $constructorMethod */
        if ($constructorMethod !== null) {
        }

        /** @var ClassMethod $notHere */
        if ($constructorMethod !== null) {
        }
    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class IfCase
{
    public function run()
    {
        /** @var ClassMethod $constructorMethod */
        if ($constructorMethod !== null) {
        }

        if ($constructorMethod !== null) {
        }
    }
}

?>
