<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

final class ExtraBreak
{
    public function run($meal)
    {
        switch ($meal) {
            case 'morning-food':
                $food = 'small chicken';
                break;
            default:
                $food = 'chicken';
                break;
        }
    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

final class ExtraBreak
{
    public function run($meal)
    {
        if ($meal == 'morning-food') {
            $food = 'small chicken';
        } else {
            $food = 'chicken';
        }
    }
}

?>
