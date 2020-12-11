<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SomeClass
{
    public function run()
    {
        if ($cond1) {
            if ($cond2) {
                return 'foo';
            }
        } else {
            return 'bar';
        }
    }
}
