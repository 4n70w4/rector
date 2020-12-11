<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class CompareToIntegerInversed
{
    public function run()
    {
        // current PHP: 10.0
        if (1 == version_compare('7.2', PHP_VERSION, '<')) {
            return 'is PHP 7.1-';
        } else {
            return 'is PHP 7.2+';
        }
    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class CompareToIntegerInversed
{
    public function run()
    {
        // current PHP: 10.0
        return 'is PHP 7.1-';
    }
}

?>
