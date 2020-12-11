<?php

namespace Rector\TypeDeclaration\Tests\Rector\FunctionLike\ParamTypeDeclarationRector\Fixture\php-cs-fixer-param;

class Foo {
    /** @param self $foo */ function my_foo($foo) {}
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\FunctionLike\ParamTypeDeclarationRector\Fixture\php-cs-fixer-param;

class Foo {
    /** @param self $foo */ function my_foo(self $foo) {}
}

?>
