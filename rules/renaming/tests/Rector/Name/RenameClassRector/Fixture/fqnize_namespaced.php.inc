<?php

class FqnizeNamespaced
{
    public function run()
    {
        return new DateTime();
    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class FqnizeNamespaced
{
    public function run()
    {
        return new \DateTime();
    }
}

?>
