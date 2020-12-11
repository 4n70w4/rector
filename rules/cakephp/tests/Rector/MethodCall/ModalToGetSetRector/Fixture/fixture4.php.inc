<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

function modalToGetSet4()
{
    $object = new Source\SomeModelType;

    $object->makeEntity();
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

function modalToGetSet4()
{
    $object = new Source\SomeModelType;

    $object->createEntity();
}

?>
