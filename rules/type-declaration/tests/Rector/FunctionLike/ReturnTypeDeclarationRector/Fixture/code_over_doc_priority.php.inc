<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class CodeOverDocPriority
{
    /**
     * @return bool
     */
    public function getNumber()
    {
        return 5;
    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class CodeOverDocPriority
{
    public function getNumber(): int
    {
        return 5;
    }
}

?>
