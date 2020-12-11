<?php

class MyOldClass
{
    /**
     * @return MyOldClass
     */
    public function createSelf(): MyOldClass
    {
        return new MyOldClass;
    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class MyNewClass
{
    /**
     * @return \Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture\MyNewClass
     */
    public function createSelf(): \Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture\MyNewClass
    {
        return new \Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture\MyNewClass;
    }
}

?>
