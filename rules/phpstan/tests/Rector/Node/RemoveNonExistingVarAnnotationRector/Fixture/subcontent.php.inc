<?php

namespace Rector\Phpstan\Tests\Rector\Node\RemoveNonExistingVarAnnotationRector\Fixture;

class Subcontent
{
    public function get()
    {
        /** @var int $trainings */
        $trainingsLonger = $this->getAnotherData();

        return $trainings;
    }
}

?>
-----
<?php

namespace Rector\Phpstan\Tests\Rector\Node\RemoveNonExistingVarAnnotationRector\Fixture;

class Subcontent
{
    public function get()
    {
        $trainingsLonger = $this->getAnotherData();

        return $trainings;
    }
}

?>
