<?php

namespace Rector\TypeDeclaration\Tests\Rector\FunctionLike\ReturnTypeDeclarationRector\Fixture\PhpCsFixerReturn;

class SkipBlacklistedClassMethods
{
}

class Foo
{
    /** @return SkipBlacklistedClassMethods */
    function __construct() {}
    /** @return SkipBlacklistedClassMethods */
    function __destruct() {}
    /** @return SkipBlacklistedClassMethods */
    function __clone() {}
}
