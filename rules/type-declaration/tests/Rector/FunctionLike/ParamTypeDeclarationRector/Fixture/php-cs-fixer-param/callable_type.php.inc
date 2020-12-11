<?php

namespace Rector\TypeDeclaration\Tests\Rector\FunctionLike\ParamTypeDeclarationRector\Fixture\php-cs-fixer-param;

/** @param callable $foo */ function my_foo($foo) {}
?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\FunctionLike\ParamTypeDeclarationRector\Fixture\php-cs-fixer-param;

/** @param callable $foo */ function my_foo(callable $foo) {}
?>
