<?php

namespace Rector\TypeDeclaration\Tests\Rector\FunctionLike\ParamTypeDeclarationRector\Fixture\php-cs-fixer-param;

class NonRootClassWithDifferentTypesOfParams
{
}

/**
 * @param string $bar
 * @param int $baz
 * @param float $tab
 */
function my_foo($bar, $baz, $tab) {}

/** @param NonRootClassWithDifferentTypesOfParams $foo */ function my_foo2($foo) {}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\FunctionLike\ParamTypeDeclarationRector\Fixture\php-cs-fixer-param;

class NonRootClassWithDifferentTypesOfParams
{
}

/**
 * @param string $bar
 * @param int $baz
 * @param float $tab
 */
function my_foo(string $bar, int $baz, float $tab) {}

/** @param NonRootClassWithDifferentTypesOfParams $foo */ function my_foo2(\Rector\TypeDeclaration\Tests\Rector\FunctionLike\ParamTypeDeclarationRector\Fixture\php-cs-fixer-param\NonRootClassWithDifferentTypesOfParams $foo) {}

?>
