<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class Bar {}

interface Foo
{
    /** @param Bar $bar */
    function my_foo($bar);
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class Bar {}

interface Foo
{
    /** @param Bar $bar */
    function my_foo(\Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture\Bar $bar);
}

?>
