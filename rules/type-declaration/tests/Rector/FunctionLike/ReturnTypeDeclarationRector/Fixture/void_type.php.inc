<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class TestVoidType
{
    /**
     * @return false
     */
    function someFunction()
    {
    }

    /**
     * @return void
     */
    function anotherFunction()
    {
        return;
    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class TestVoidType
{
    /**
     * @return false
     */
    function someFunction(): void
    {
    }

    function anotherFunction(): void
    {
        return;
    }
}

?>
