<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

trait BazTrait
{
    /**
     * @param int $a
     *
     * @return \DateTime
     */
    protected function inTrait($a)
    {
    }
}
?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

trait BazTrait
{
    /**
     * @param int $a
     *
     * @return \DateTime
     */
    protected function inTrait(int $a)
    {
    }
}
?>
