<?php

namespace Rector\TypeDeclaration\Tests\Rector\FunctionLike\ReturnTypeDeclarationRector\Fixture\PhpCsFixerReturn;

class Bar
{
}

class Foo
{
    /** @return Bar */
    function __construct() {}
    /** @return Bar */
    function __destruct() {}
    /** @return Bar */
    function __clone() {}
}
