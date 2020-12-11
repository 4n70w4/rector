<?php

namespace Rector\TypeDeclaration\Tests\Rector\FunctionLike\ReturnTypeDeclarationRector\Fixture;

class KnownStaticObjectParent
{

}

class Child extends KnownStaticObjectParent
{

}

class KnownStaticObjectParent
{
    public function run()
    {
        $value = new Child();

        return $value;
    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\FunctionLike\ReturnTypeDeclarationRector\Fixture;

class KnownStaticObjectParent
{

}

class Child extends KnownStaticObjectParent
{

}

class KnownStaticObjectParent
{
    public function run(): \Rector\TypeDeclaration\Tests\Rector\FunctionLike\ReturnTypeDeclarationRector\Fixture\Child
    {
        $value = new Child();

        return $value;
    }
}

?>
