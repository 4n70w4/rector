<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

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

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

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
