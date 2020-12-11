<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SomeClass
{
    public function foo()
    {
        $class = new class()
        {
            public function foo()
            {
                parent::foo();
            }
        };
    }
}
?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SomeClass
{
    public function foo()
    {
        $class = new class()
        {
            public function foo()
            {
            }
        };
    }
}
?>
