<?php

namespace Rector\TypeDeclaration\Tests\Rector\FunctionLike\ParamTypeDeclarationRector\Fixture\php-cs-fixer-param;

/** @param \My\Bar $foo */ function my_foo($foo) {}
?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\FunctionLike\ParamTypeDeclarationRector\Fixture\php-cs-fixer-param;

/** @param \My\Bar $foo */ function my_foo(\My\Bar $foo) {}
?>
