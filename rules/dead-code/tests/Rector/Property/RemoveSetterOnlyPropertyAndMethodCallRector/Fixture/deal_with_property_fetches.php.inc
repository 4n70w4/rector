<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class MyClass
{
    private $unused;
    private $prop;

    public function __construct($unused)
    {
        $this->unused = $unused;
    }

    public function foo()
    {
        $this->prop[] = 'foo';

    }
}
?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class MyClass
{
    public function __construct()
    {
    }
}
?>
