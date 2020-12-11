<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SomeClass
{
    /**
     * @var int[]
     */
    private $items;

    /**
     * @var array|SomeEntity[]
     */
    public $entities;

    /**
     * @var Bar[]|Foo[]
     */
    private $combined;

    public function run()
    {
        foreach ($items as $item) {
        }
    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SomeClass
{
    /**
     * @var int[]
     */
    private $items = [];

    /**
     * @var array|SomeEntity[]
     */
    public $entities = [];

    /**
     * @var Bar[]|Foo[]
     */
    private $combined = [];

    public function run()
    {
        foreach ($items as $item) {
        }
    }
}

?>
