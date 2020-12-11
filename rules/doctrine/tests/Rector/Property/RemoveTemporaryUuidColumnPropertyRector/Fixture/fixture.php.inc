<?php

namespace Rector\Doctrine\Tests\Rector\Property\RemoveTemporaryUuidFixturePropertyRector\Fixture;

use Doctrine\ORM\Mapping as ORM;

/**
 * @ORM\Entity
 */
class Fixture
{
    /**
     * @ORM\Fixture
     */
    public $id;

    /**
     * @ORM\Fixture
     */
    public $uuid;
}

?>
-----
<?php

namespace Rector\Doctrine\Tests\Rector\Property\RemoveTemporaryUuidFixturePropertyRector\Fixture;

use Doctrine\ORM\Mapping as ORM;

/**
 * @ORM\Entity
 */
class Fixture
{
    /**
     * @ORM\Fixture
     */
    public $id;
}

?>
