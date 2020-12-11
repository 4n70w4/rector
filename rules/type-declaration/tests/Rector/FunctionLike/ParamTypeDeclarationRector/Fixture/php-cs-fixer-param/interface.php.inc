<?php

namespace Rector\TypeDeclaration\Tests\Rector\FunctionLike\ParamTypeDeclarationRector\Fixture\php-cs-fixer-param;

class Bar {}

interface Foo
{
    /** @param Bar $bar */
    function my_foo($bar);
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\FunctionLike\ParamTypeDeclarationRector\Fixture\php-cs-fixer-param;

class Bar {}

interface Foo
{
    /** @param Bar $bar */
    function my_foo(\Rector\TypeDeclaration\Tests\Rector\FunctionLike\ParamTypeDeclarationRector\Fixture\php-cs-fixer-param\Bar $bar);
}

?>
