<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class Foo {
    /** @param self $foo */ function my_foo($foo) {}
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class Foo {
    /** @param self $foo */ function my_foo(self $foo) {}
}

?>
