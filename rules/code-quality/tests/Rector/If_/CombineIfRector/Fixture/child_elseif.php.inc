<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SomeClass
{
    public function run()
    {
        if ($cond1) {
            if ($cond2) {
                return 'foo';
            } elseif($cond3) {
                return 'bar';
            }
        }
    }
}
