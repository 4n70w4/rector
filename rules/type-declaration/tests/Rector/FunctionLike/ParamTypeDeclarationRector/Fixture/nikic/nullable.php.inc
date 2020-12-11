<?php

namespace Rector\TypeDeclaration\Tests\Rector\FunctionLike\ParamTypeDeclarationRector\Fixture\nikic;

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

namespace Rector\TypeDeclaration\Tests\Rector\FunctionLike\ParamTypeDeclarationRector\Fixture\nikic;

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
function test2(?\Rector\TypeDeclaration\Tests\Rector\FunctionLike\ParamTypeDeclarationRector\Fixture\nikic\Foo $a, ?\Rector\TypeDeclaration\Tests\Rector\FunctionLike\ParamTypeDeclarationRector\Fixture\nikic\Bar $b = null) {}

?>
