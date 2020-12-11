<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SomeClass
{
    public function foo()
    {
        $class = new class() extends Base
        {
            public function foo()
            {
                parent::foo();
            }
        };
    }
}

class Base
{
    public function foo()
    {

    }
}
