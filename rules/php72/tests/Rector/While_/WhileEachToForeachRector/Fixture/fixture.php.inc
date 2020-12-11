<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

function each1()
{
    while (list($key, $callback) = each($callbacks)) {
        // comment
    }

    $module_list = ['a', 'b'];

    while (list($module) = each($module_list)) {
        echo $module;
    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

function each1()
{
    foreach ($callbacks as $key => $callback) {
        // comment
    }

    $module_list = ['a', 'b'];

    foreach (array_keys($module_list) as $module) {
        echo $module;
    }
}

?>
