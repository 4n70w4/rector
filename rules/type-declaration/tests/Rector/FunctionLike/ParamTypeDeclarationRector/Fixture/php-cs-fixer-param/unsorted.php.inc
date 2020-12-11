<?php

namespace Rector\TypeDeclaration\Tests\Rector\FunctionLike\ParamTypeDeclarationRector\Fixture\php-cs-fixer-param;

class Unsorted
{
}

/**
 * @param int $foo
 * @param string $bar
 * @param Unsorted $hey
 * @param float $tab
 * @param bool $baz
 */
function my_foo($bar, $foo, $baz, $tab, $hey) {}
?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\FunctionLike\ParamTypeDeclarationRector\Fixture\php-cs-fixer-param;

class Unsorted
{
}

/**
 * @param int $foo
 * @param string $bar
 * @param Unsorted $hey
 * @param float $tab
 * @param bool $baz
 */
function my_foo(string $bar, int $foo, bool $baz, float $tab, \Rector\TypeDeclaration\Tests\Rector\FunctionLike\ParamTypeDeclarationRector\Fixture\php-cs-fixer-param\Unsorted $hey) {}
?>
