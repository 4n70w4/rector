<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SkipNonVoidReturnClass
{
    public function canDrive(Car $car): ?bool
    {
        if ($car->hasWheels && $car->hasFuel) {
            return false;
        }

        return true;
    }
}

?>
