<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SomeClass
{
    public function run()
    {
        if ($cond1) {

        } else {
            foo();
            return 'bar';
        }
    }
}

?>
