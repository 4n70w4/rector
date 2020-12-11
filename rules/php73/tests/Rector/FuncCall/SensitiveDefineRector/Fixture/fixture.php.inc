<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

function sensitiveDefine()
{
    define('FOO', 42, true);
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

function sensitiveDefine()
{
    define('FOO', 42);
}

?>
