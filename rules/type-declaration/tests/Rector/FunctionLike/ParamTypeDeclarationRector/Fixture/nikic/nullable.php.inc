<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class Foo
{
}

class Bar
{
}

/**
 * @param Foo|null $a
 * @param Bar|null $b
 */
function test2($a, $b = null) {}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class Foo
{
}

class Bar
{
}

/**
 * @param Foo|null $a
 * @param Bar|null $b
 */
function test2(?\Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture\Foo $a, ?\Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture\Bar $b = null) {}

?>
