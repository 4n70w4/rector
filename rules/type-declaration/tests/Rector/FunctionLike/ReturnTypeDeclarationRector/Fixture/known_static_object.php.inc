<?php

namespace Rector\TypeDeclaration\Tests\Rector\FunctionLike\ReturnTypeDeclarationRector\Fixture;

class KnownStaticObject
{

}

class KnownStaticObject
{
    public function getObject()
    {
        $object = new \stdClass;
        return $object;
    }

    public function getKnownStaticObject()
    {
        $object = new KnownStaticObject();
        return $object;
    }

    public function getMaybe($value)
    {
        $object = null;
        if ($value) {
            $object = new \stdClass;
        }
        return $object;
    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\FunctionLike\ReturnTypeDeclarationRector\Fixture;

class KnownStaticObject
{

}

class KnownStaticObject
{
    public function getObject(): \stdClass
    {
        $object = new \stdClass;
        return $object;
    }

    public function getKnownStaticObject(): \Rector\TypeDeclaration\Tests\Rector\FunctionLike\ReturnTypeDeclarationRector\Fixture\KnownStaticObject
    {
        $object = new KnownStaticObject();
        return $object;
    }

    public function getMaybe($value): ?\stdClass
    {
        $object = null;
        if ($value) {
            $object = new \stdClass;
        }
        return $object;
    }
}

?>
