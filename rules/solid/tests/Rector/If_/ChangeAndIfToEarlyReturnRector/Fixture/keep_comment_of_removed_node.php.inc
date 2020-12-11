<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class KeepCommentOfRemovedNodeClass
{
    public function canDrive(Car $car): void
    {
        // keep this comment
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

class KeepCommentOfRemovedNodeClass
{
    public function canDrive(Car $car): void
    {
        // keep this comment
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
