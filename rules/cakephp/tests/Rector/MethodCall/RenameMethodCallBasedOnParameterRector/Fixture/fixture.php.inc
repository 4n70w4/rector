<?php

namespace Rector\Cakephp\Tests\Rector\MethodCall\RenameMethodCallBasedOnParameterRector\Fixture;

function renameMethodCallBasedOnParameter()
{
    $object = new Source\SomeModelType;

    $config = $object->getParam('paging');
    $object->withParam('paging', 'value');
}

?>
-----
<?php

namespace Rector\Cakephp\Tests\Rector\MethodCall\RenameMethodCallBasedOnParameterRector\Fixture;

function renameMethodCallBasedOnParameter()
{
    $object = new Source\SomeModelType;

    $config = $object->getAttribute('paging');
    $object->withAttribute('paging', 'value');
}

?>
