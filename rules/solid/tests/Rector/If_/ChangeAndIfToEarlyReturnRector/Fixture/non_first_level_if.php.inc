<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class NonFirstLevelIfClass
{
    public function canDrive(Car $car): void
    {
        if ($car->wheelsCount() > 2) {
            if ($car->hasWheels && $car->hasFuel) {
                $this->canDrive = true;
            }
        }
    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class NonFirstLevelIfClass
{
    public function canDrive(Car $car): void
    {
        if ($car->wheelsCount() > 2) {
            if (!$car->hasWheels) {
                return;
            }
            if (!$car->hasFuel) {
                return;
            }
            $this->canDrive = true;
        }
    }
}

?>
