<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

function arrayToFluentCall()
{
    $factory = new Source\FactoryClass();

    $factory->buildClass('foo');

    $factory->buildClass('foo', []);

    $factory->buildClass('foo', ['baz' => 1]);
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

function arrayToFluentCall()
{
    $factory = new Source\FactoryClass();

    $factory->buildClass('foo');

    $factory->buildClass('foo');

    $factory->buildClass('foo', ['baz' => 1]);
}

?>
