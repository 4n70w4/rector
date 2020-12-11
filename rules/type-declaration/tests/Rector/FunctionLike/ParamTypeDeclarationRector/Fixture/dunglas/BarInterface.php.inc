<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

interface BarInterface
{
    /**
     * @param array $a
     * @param int   $b
     *
     * @return float
     */
    public function baz(array $a, $b);
}
?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

interface BarInterface
{
    /**
     * @param array $a
     * @param int   $b
     *
     * @return float
     */
    public function baz(array $a, int $b);
}
?>
