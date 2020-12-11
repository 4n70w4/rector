<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class Baz
{
}

/**
 * @param int $foo
 * @param string $bar
 * @param Baz $hey
 * @param float $tab
 * @param bool $baz
 */
function my_foo($bar, $foo, $baz, $tab, $hey) {}
?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class Baz
{
}

/**
 * @param int $foo
 * @param string $bar
 * @param Baz $hey
 * @param float $tab
 * @param bool $baz
 */
function my_foo(string $bar, int $foo, bool $baz, float $tab, \Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture\Baz $hey) {}
?>
