<?php

namespace Rector\TypeDeclaration\Tests\Rector\FunctionLike\ParamTypeDeclarationRector\Fixture\nikic;

class Null
{
}

/** @return null */
function foo() {
    return null;
}

/** @param null $a */
function foo2($a) {}

/** @param null|Null $a */
function foo3($a = null) {}

/** @param null|Null $a */
function foo4($a) {}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\FunctionLike\ParamTypeDeclarationRector\Fixture\nikic;

class Null
{
}

/** @return null */
function foo() {
    return null;
}

/** @param null $a */
function foo2($a) {}

/** @param null|Null $a */
function foo3(?\Rector\TypeDeclaration\Tests\Rector\FunctionLike\ParamTypeDeclarationRector\Fixture\nikic\Null $a = null) {}

/** @param null|Null $a */
function foo4(?\Rector\TypeDeclaration\Tests\Rector\FunctionLike\ParamTypeDeclarationRector\Fixture\nikic\Null $a) {}

?>
