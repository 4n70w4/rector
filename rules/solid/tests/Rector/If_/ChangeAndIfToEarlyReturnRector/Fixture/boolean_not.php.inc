<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class BooleanNotClass
{
    public function canDrive(Car $car)
    {
        if (!$car->hasWheels && !$car->hasFuel) {
            $this->canDrive = true;
        }

        return;
    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class BooleanNotClass
{
    public function canDrive(Car $car)
    {
        if ($car->hasWheels) {
            return;
        }
        if ($car->hasFuel) {
            return;
        }
        $this->canDrive = true;
    }
}

?>
