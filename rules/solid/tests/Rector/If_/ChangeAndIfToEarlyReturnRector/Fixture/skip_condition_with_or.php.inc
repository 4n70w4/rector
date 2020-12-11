<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SkipConditionWithOr
{
    public function canDrive(Car $car)
    {
        if ($car->hasWheels || $car->hasFuel) {
            $this->canDrive = false;
        }

        return;
    }
}

?>
