<?php

namespace Rector\Generic\Tests\Rector\Class_\RemoveTraitRector\Fixture;

use Rector\Generic\Tests\Rector\Class_\RemoveTraitRector\Source\TraitToBeRemoved;

class Fixture
{
    use TraitToBeRemoved;
}

?>
-----
<?php

namespace Rector\Generic\Tests\Rector\Class_\RemoveTraitRector\Fixture;

use Rector\Generic\Tests\Rector\Class_\RemoveTraitRector\Source\TraitToBeRemoved;

class Fixture
{
}

?>
