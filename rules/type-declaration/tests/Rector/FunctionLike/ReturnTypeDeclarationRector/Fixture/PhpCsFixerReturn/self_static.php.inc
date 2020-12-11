<?php

namespace Rector\TypeDeclaration\Tests\Rector\FunctionLike\ReturnTypeDeclarationRector\Fixture\PhpCsFixerReturn;

class Foo {
    /** @return self */
    function my_foo($value)
    {
        return $value;
    }
}

class Foo2 {
    /** @return static */
    function my_foo($value)
    {
        return $value;
    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\FunctionLike\ReturnTypeDeclarationRector\Fixture\PhpCsFixerReturn;

class Foo {
    function my_foo($value): self
    {
        return $value;
    }
}

class Foo2 {
    /** @return static */
    function my_foo($value)
    {
        return $value;
    }
}

?>
