<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

interface BarInterface
{
    /**
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
    public function baz(array $a, $b): float;
}
?>
