<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

trait BazTrait
{
    /**
     * @return \DateTime
     */
    protected function inTrait($a)
    {
        return $a;
    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

trait BazTrait
{
    protected function inTrait($a): \DateTime
    {
        return $a;
    }
}

?>
