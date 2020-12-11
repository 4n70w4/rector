<?php

namespace Rector\TypeDeclaration\Tests\Rector\FunctionLike\ParamTypeDeclarationRector\Fixture\nikic;

class Nullable
{
}

class Bar
{
}

/**
 * @param Nullable|null $a
 * @param Bar|null $b
 */
function test2($a, $b = null) {}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\FunctionLike\ParamTypeDeclarationRector\Fixture\nikic;

class Nullable
{
}

class Bar
{
}

/**
 * @param Nullable|null $a
 * @param Bar|null $b
 */
function test2(?\Rector\TypeDeclaration\Tests\Rector\FunctionLike\ParamTypeDeclarationRector\Fixture\nikic\Nullable $a, ?\Rector\TypeDeclaration\Tests\Rector\FunctionLike\ParamTypeDeclarationRector\Fixture\nikic\Bar $b = null) {}

?>
