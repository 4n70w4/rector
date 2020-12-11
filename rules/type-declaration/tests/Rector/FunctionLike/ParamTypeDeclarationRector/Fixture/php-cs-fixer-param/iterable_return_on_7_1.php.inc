<?php

namespace Rector\TypeDeclaration\Tests\Rector\FunctionLike\ParamTypeDeclarationRector\Fixture\php-cs-fixer-param;

/** @param iterable $counter */ function my_foo($counter) {}
?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\FunctionLike\ParamTypeDeclarationRector\Fixture\php-cs-fixer-param;

/** @param iterable $counter */ function my_foo(iterable $counter) {}
?>
