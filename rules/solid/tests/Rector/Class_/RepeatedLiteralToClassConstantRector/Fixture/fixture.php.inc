<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SomeClass
{
    public function run($key, $items)
    {
        if ($key === 'requires') {
            return $items['requires'];
        }

        return $items['requires'];
    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SomeClass
{
    /**
     * @var string
     */
    private const REQUIRES = 'requires';
    public function run($key, $items)
    {
        if ($key === self::REQUIRES) {
            return $items[self::REQUIRES];
        }

        return $items[self::REQUIRES];
    }
}

?>
