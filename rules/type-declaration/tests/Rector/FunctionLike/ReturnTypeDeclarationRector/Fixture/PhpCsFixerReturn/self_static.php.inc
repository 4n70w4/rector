<?php

namespace Rector\TypeDeclaration\Tests\Rector\FunctionLike\ReturnTypeDeclarationRector\Fixture\PhpCsFixerReturn;

class SelfStatic {
    /** @return self */
    function my_foo($value)
    {
        return $value;
    }
}

class SelfStatic2 {
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

class SelfStatic {
    function my_foo($value): self
    {
        return $value;
    }
}

class SelfStatic2 {
    /** @return static */
    function my_foo($value)
    {
        return $value;
    }
}

?>
