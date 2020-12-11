<?php

namespace Rector\TypeDeclaration\Tests\Rector\FunctionLike\ParamTypeDeclarationRector\Fixture;

class ReferenceSymbolInDocblock
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

namespace Rector\TypeDeclaration\Tests\Rector\FunctionLike\ParamTypeDeclarationRector\Fixture;

class ReferenceSymbolInDocblock
{
    /**
     * @param array &$value
     */
    public function someFunction(array &$value)
    {
    }
}
?>
