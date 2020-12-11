<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class IfElse
{
    private function foo($condition)
    {
        if ($condition) {
            exit;
            $code = 'unused';
        } else {
            $someCode = 'used';
        }

        if ($condition) {
            $someCode = 'used';
        } else {
            exit;
            $code = 'unused';
        }
    }
}
?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class IfElse
{
    private function foo($condition)
    {
        if ($condition) {
            exit;
        } else {
            $someCode = 'used';
        }

        if ($condition) {
            $someCode = 'used';
        } else {
            exit;
        }
    }
}
?>
