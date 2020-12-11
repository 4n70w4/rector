<?php

namespace Rector\TypeDeclaration\Tests\Rector\FunctionLike\ReturnTypeDeclarationRector\Fixture\nikic;

class Object {
    /** @return object */
    public function getObject($value) {
        return $value;
    }
}
class B extends Object {
    /** @return Foo */
    public function getObject($value) {
        return $value;
    }
}
?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\FunctionLike\ReturnTypeDeclarationRector\Fixture\nikic;

class Object {
    public function getObject($value): object {
        return $value;
    }
}
class B extends Object {
    /** @return Foo */
    public function getObject($value): object {
        return $value;
    }
}
?>
