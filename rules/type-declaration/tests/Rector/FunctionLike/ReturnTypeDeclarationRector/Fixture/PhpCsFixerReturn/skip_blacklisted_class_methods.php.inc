<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

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
