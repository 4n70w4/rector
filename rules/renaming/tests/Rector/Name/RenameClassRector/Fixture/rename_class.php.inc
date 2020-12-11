<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class MyClass
{
    /**
     * @return MyClass
     */
    public function createSelf(): MyClass
    {
        return new MyClass;
    }
}

?>
-----
<?php

namespace MyNewNamespace;

class MyNewClass
{
    /**
     * @return \MyNewNamespace\MyNewClass
     */
    public function createSelf(): \MyNewNamespace\MyNewClass
    {
        return new \MyNewNamespace\MyNewClass;
    }
}

?>
