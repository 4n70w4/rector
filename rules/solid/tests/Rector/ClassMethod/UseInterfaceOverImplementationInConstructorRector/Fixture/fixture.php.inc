<?php

namespace Rector\Solid\Tests\Rector\ClassMethod\UseInterfaceOverImplementationInConstructorRector\Fixture;

class SomeClass
{
    public function __construct(\Rector\Solid\Tests\Rector\ClassMethod\UseInterfaceOverImplementationInConstructorRector\Fixture\SomeImplementation $someImplementation)
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

namespace Rector\Solid\Tests\Rector\ClassMethod\UseInterfaceOverImplementationInConstructorRector\Fixture;

class SomeClass
{
    public function __construct(\Rector\Solid\Tests\Rector\ClassMethod\UseInterfaceOverImplementationInConstructorRector\Fixture\SomeInterface $someImplementation)
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
