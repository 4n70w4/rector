<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class ReferenceSymbolInDocBlock
{
    /**
     * @param array &$value
     */
    public function someFunction(&$value)
    {
    }
}
?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class ReferenceSymbolInDocBlock
{
    /**
     * @param array &$value
     */
    public function someFunction(array &$value)
    {
    }
}
?>
