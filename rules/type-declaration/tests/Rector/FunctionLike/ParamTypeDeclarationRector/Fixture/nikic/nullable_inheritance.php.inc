<?php

namespace Rector\TypeDeclaration\Tests\Rector\FunctionLike\ParamTypeDeclarationRector\Fixture\nikic;

class NullableInheritance {
    /** @param Foo $a */
    public function test2($a) {}
}

class B extends A {
    /** @param null|Foo $a */
    public function test2($a) {}
}
?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\FunctionLike\ParamTypeDeclarationRector\Fixture\nikic;

class NullableInheritance {
    /** @param Foo $a */
    public function test2(\Rector\TypeDeclaration\Tests\Rector\FunctionLike\ParamTypeDeclarationRector\Fixture\nikic\Foo $a) {}
}

class B extends A {
    /** @param null|Foo $a */
    public function test2(?\Rector\TypeDeclaration\Tests\Rector\FunctionLike\ParamTypeDeclarationRector\Fixture\nikic\Foo $a) {}
}
?>
