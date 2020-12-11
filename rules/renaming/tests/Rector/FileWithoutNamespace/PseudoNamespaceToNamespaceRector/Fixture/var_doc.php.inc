<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class VarDoc
{
    /**
     * @var \PHPUnit_Framework_TestCase
     */
    public $test;
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class VarDoc
{
    /**
     * @var \PHPUnit\Framework\TestCase
     */
    public $test;
}

?>
