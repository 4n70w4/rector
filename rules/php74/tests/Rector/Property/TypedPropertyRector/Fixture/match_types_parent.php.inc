<?php

namespace Rector\Php74\Tests\Rector\Property\TypedPropertyRector\Fixture;

class MatchTypesParent
{

}

final class MatchTypesParent extends MatchTypesParent
{
    /**
     * @var parent
     */
    private $j;
}

?>
-----
<?php

namespace Rector\Php74\Tests\Rector\Property\TypedPropertyRector\Fixture;

class MatchTypesParent
{

}

final class MatchTypesParent extends MatchTypesParent
{
    private parent $j;
}

?>
