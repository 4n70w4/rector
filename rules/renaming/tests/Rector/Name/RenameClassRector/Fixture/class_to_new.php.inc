<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class MyCustomValidatorTest extends \Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture\Source\OldClass
{
    // ...
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class MyCustomValidatorTest extends \Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture\Source\NewClass
{
    // ...
}

?>
