<?php

namespace Rector\TypeDeclaration\Tests\Rector\FunctionLike\ReturnTypeDeclarationRector\Fixture\dunglas;

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

namespace Rector\TypeDeclaration\Tests\Rector\FunctionLike\ReturnTypeDeclarationRector\Fixture\dunglas;

interface BarInterface
{
    public function baz(array $a, $b): float;
}
?>
