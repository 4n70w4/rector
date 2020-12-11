<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class MoreThanTwoConditionsClass
{
    public function canDrive(Car $car): void
    {
        if ($car->hasWheels && $car->hasFuel && $car->hasEngine) {
            $this->canDrive = true;
        }
    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class MoreThanTwoConditionsClass
{
    public function canDrive(Car $car): void
    {
        if (!$car->hasWheels) {
            return;
        }
        if (!$car->hasFuel) {
            return;
        }
        if (!$car->hasEngine) {
            return;
        }
        $this->canDrive = true;
    }
}

?>
