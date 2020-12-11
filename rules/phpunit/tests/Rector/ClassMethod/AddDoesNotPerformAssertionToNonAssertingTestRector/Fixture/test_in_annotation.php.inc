<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class TestInAnnotatoin extends \PHPUnit\Framework\TestCase
{
    /**
     * @test
     */
    public function thisIsTest()
    {
        $nothing = 5;
    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class TestInAnnotatoin extends \PHPUnit\Framework\TestCase
{
    /**
     * @test
     * @doesNotPerformAssertions
     */
    public function thisIsTest()
    {
        $nothing = 5;
    }
}

?>
