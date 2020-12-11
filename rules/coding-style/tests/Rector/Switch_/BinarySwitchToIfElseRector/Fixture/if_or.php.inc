<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

final class IfOr
{
    public function run($value)
    {
        switch ($value) {
            case 'T_OPEN_SQUARE_BRACKET':
            case 'T_OBJECT':
                // skip to closing bracket
                $position = $value;
                break;
        }
    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

final class IfOr
{
    public function run($value)
    {
        if ($value == 'T_OPEN_SQUARE_BRACKET' || $value == 'T_OBJECT') {
            // skip to closing bracket
            $position = $value;
        }
    }
}

?>
