<?php

namespace Rector\TypeDeclaration\Tests\Rector\FunctionLike\ParamTypeDeclarationRector\Fixture\nikic;

/** @param \Traversable|array $a */
function test($a) {}

/** @param array|\Traversable|null $a */
function test2($a) {}
?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\FunctionLike\ParamTypeDeclarationRector\Fixture\nikic;

/** @param \Traversable|array $a */
function test(iterable $a) {}

/** @param array|\Traversable|null $a */
function test2(?iterable $a) {}
?>
