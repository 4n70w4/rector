<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SomeClassTest
{
    public function test()
    {
        $someClass = new SomeClass();
    }
}

?>
-----
<?php

namespace Rector\PSR4\Tests\Rector\FileWithoutNamespace\NormalizeNamespaceByPSR4ComposerAutoloadRector\Fixture;

class SomeClassTest
{
    public function test()
    {
        $someClass = new \Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture\SomeClass();
    }
}

?>
