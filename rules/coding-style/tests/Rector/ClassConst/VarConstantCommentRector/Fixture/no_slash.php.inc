<?php

declare(strict_types=1);

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SomeClass
{
    /**
     * Some text comment
     */
    private const CONTROLS_MAPPING = [['a']];
}

?>
-----
<?php

declare(strict_types=1);

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SomeClass
{
    /**
     * Some text comment
     * @var string[][]
     */
    private const CONTROLS_MAPPING = [['a']];
}

?>
