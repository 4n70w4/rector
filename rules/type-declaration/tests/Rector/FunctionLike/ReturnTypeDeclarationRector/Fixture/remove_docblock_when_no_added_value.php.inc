<?php

namespace Rector\TypeDeclaration\Tests\Rector\FunctionLike\ReturnTypeDeclarationRector\Fixture;

class RemoveDocblockWhenNoAddedValue
{
    /**
     * @return float
     */
    public function getSize()
    {
        return 10.5;
    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\FunctionLike\ReturnTypeDeclarationRector\Fixture;

class RemoveDocblockWhenNoAddedValue
{
    public function getSize(): float
    {
        return 10.5;
    }
}

?>
