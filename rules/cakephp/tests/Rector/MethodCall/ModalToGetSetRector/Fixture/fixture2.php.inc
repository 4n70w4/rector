<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

function modalToGetSet2()
{
    $object = new Source\SomeModelType;

    $config = $object->customMethod();
    $config = $object->customMethod('key');

    $object->customMethod('key', 'value');
    $object->customMethod(['key' => 'value']);
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

function modalToGetSet2()
{
    $object = new Source\SomeModelType;

    $config = $object->customMethodGetName();
    $config = $object->customMethodGetName('key');

    $object->customMethodSetName('key', 'value');
    $object->customMethodSetName(['key' => 'value']);
}

?>
