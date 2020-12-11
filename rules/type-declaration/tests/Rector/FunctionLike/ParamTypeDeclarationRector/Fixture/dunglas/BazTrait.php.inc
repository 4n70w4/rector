<?php

namespace Rector\TypeDeclaration\Tests\Rector\FunctionLike\ParamTypeDeclarationRector\Fixture\dunglas;

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

namespace Rector\TypeDeclaration\Tests\Rector\FunctionLike\ParamTypeDeclarationRector\Fixture\dunglas;

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
