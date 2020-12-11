<?php

namespace Rector\Generic\Tests\Rector\Property\ChangePropertyVisibilityRector\Fixture;

use Rector\Generic\Tests\Rector\Property\ChangePropertyVisibilityRector\Source\ParentObject;

class Fixture
{
    public $toBeProtectedProperty;

    protected $toBePrivateProperty;
}

?>
-----
<?php

namespace Rector\Generic\Tests\Rector\Property\ChangePropertyVisibilityRector\Fixture;

use Rector\Generic\Tests\Rector\Property\ChangePropertyVisibilityRector\Source\ParentObject;

class Fixture
{
    protected $toBeProtectedProperty;

    private $toBePrivateProperty;
}

?>
