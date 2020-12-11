<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

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

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class Subcontent
{
    public function get()
    {
        $trainingsLonger = $this->getAnotherData();

        return $trainings;
    }
}

?>
