<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SomeClass
{
    public function canDrive(Car $car): void
    {
        if ($car->hasWheels && $car->hasFuel) {
            $this->canDrive = true;
        }

        return;
    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SomeClass
{
    public function canDrive(Car $car): void
    {
        if (!$car->hasWheels) {
            return;
        }
        if (!$car->hasFuel) {
            return;
        }
        $this->canDrive = true;
    }
}

?>
