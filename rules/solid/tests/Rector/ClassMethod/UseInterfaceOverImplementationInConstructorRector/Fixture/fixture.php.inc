<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SomeClass
{
    public function __construct(\Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture\SomeImplementation $someImplementation)
    {
    }
}

class SomeImplementation implements SomeInterface
{
}

interface SomeInterface
{
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SomeClass
{
    public function __construct(\Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture\SomeInterface $someImplementation)
    {
    }
}

class SomeImplementation implements SomeInterface
{
}

interface SomeInterface
{
}

?>
