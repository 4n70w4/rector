<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class Foo
{}

class A {
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

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class Foo
{}

class A {
    /** @param Foo $a */
    public function test2(\Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture\Foo $a) {}
}

class B extends A {
    /** @param null|Foo $a */
    public function test2(?\Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture\Foo $a) {}
}
?>
