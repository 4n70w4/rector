<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SomeClass
{
    private $prop;

    public function doThing()
    {
        $this->prop = foo();

        $this->prop[bar()] = foo();

        return $this->prop[bar()] = foo();
    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SomeClass
{
    public function doThing()
    {
        foo();
        bar();
        foo();
        bar();
        return foo();
    }
}

?>
