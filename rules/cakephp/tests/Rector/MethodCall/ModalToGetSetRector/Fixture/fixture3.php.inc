<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

function modalToGetSet3()
{
    $object = new Source\SomeModelType;

    $config = $object->method();
    $config = $object->method('key');
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

function modalToGetSet3()
{
    $object = new Source\SomeModelType;

    $config = $object->getMethod();
    $config = $object->setMethod('key');
}

?>
