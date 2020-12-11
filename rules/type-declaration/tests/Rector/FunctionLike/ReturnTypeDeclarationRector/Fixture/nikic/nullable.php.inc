<?php

namespace Rector\TypeDeclaration\Tests\Rector\FunctionLike\ReturnTypeDeclarationRector\Fixture\nikic;

class Foo {}

/** @return Foo|null */
function test($value) {
    return $value;
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\FunctionLike\ReturnTypeDeclarationRector\Fixture\nikic;

class Foo {}

function test($value): ?\Rector\TypeDeclaration\Tests\Rector\FunctionLike\ReturnTypeDeclarationRector\Fixture\nikic\Foo {
    return $value;
}

?>
