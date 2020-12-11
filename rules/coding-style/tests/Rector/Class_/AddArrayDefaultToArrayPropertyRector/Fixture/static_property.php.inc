<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class StaticProperty
{
    /** @var int[] */
    public static $property;

    /** @var int[][] */
    public $doubleArray;
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class StaticProperty
{
    /** @var int[] */
    public static $property = [];

    /** @var int[][] */
    public $doubleArray = [];
}

?>
