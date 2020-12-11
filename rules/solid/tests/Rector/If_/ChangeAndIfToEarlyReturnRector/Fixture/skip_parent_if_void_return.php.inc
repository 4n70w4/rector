<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SkipParentIfWithVoidReturn
{
    public function canDrive(Car $car): void
    {
        if ($car->isFerrari) {
            if ($car->hasWheels && $car->hasFuel) {
                $this->canDrive = true;
            }

            return;
        }

        $this->canDrive = false;
    }
}

?>
