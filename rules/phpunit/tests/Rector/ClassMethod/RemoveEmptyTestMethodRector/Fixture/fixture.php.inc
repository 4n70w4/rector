<?php

namespace Rector\PHPUnit\Tests\Rector\ClassMethod\RemoveEmptyTestMethodRector\Fixture;

class Fixture
{
    /**
     * testGetTranslatedModelField method
     *
     * @return void
     */
    public function testGetTranslatedModelField()
    {
    }
}

?>
-----
<?php

namespace Rector\PHPUnit\Tests\Rector\ClassMethod\RemoveEmptyTestMethodRector\Fixture;

class Fixture
{
}

?>
