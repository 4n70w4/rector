<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

trait MyTrait
{
}

?>
-----
<?php

namespace MyNewNamespace;

trait MyNewTrait
{
}

?>
