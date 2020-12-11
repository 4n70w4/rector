<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SkipNotBeforeFirstLevelReturnClass
{
    public function canDrive(Car $car)
    {
        if ($car->hasWheels && $car->hasFuel) {
            $this->canDrive = true;
        }

        if (!$car->hasLights || !$car->hasEngine) {
            $this->canDrive = false;
        }

        return;
    }
}

?>
