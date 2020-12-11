<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SomeClass
{
    function run()
    {
        $object = new Source\SomeModelType;

        $config = $object->config();
        $config = $object->config('key');
        $object->config('key', 'value');
        $object->config(['key' => 'value']);
        $object->config('key');
    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SomeClass
{
    function run()
    {
        $object = new Source\SomeModelType;

        $config = $object->getConfig();
        $config = $object->getConfig('key');
        $object->setConfig('key', 'value');
        $object->setConfig(['key' => 'value']);
        $object->getConfig('key');
    }
}

?>
