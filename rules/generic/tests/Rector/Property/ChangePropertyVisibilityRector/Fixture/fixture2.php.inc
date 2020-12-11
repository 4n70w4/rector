<?php

namespace Rector\Generic\Tests\Rector\Property\ChangePropertyVisibilityRector\Fixture;

use Rector\Generic\Tests\Rector\Property\ChangePropertyVisibilityRector\Source\ParentObject;

class Fixture2
{
    private static $toBePublicStaticProperty;
}

?>
-----
<?php

namespace Rector\Generic\Tests\Rector\Property\ChangePropertyVisibilityRector\Fixture;

use Rector\Generic\Tests\Rector\Property\ChangePropertyVisibilityRector\Source\ParentObject;

class Fixture2
{
    public static $toBePublicStaticProperty;
}

?>
