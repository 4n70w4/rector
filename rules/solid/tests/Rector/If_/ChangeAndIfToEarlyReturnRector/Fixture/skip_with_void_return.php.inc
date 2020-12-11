<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SkipWithVoidReturn
{
    public function canDrive(Car $car): void
    {
        if ($car->isFerrari) {
            if ($car->hasWheels && $car->hasFuel) {
                return;
            }
        }

        $this->canDrive = true;
    }
}

?>
