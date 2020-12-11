<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class KnownStaticVoid
{
    public function nothing()
    {
    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class KnownStaticVoid
{
    public function nothing(): void
    {
    }
}

?>
