<?php

namespace Rector\DoctrineGedmoToKnplabs\Tests\Rector\Class_\TimestampableBehaviorRector\Fixture;

use Gedmo\Timestampable\Traits\TimestampableEntity;

class Fixture
{
    use TimestampableEntity;
}

?>
-----
<?php

namespace Rector\DoctrineGedmoToKnplabs\Tests\Rector\Class_\TimestampableBehaviorRector\Fixture;

use Gedmo\Timestampable\Traits\TimestampableEntity;

class Fixture implements \Knp\DoctrineBehaviors\Contract\Entity\TimestampableInterface
{
    use \Knp\DoctrineBehaviors\Model\Timestampable\TimestampableTrait;
}

?>
