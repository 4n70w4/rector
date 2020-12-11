<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

/**
 * This is here
 */
class AddToDocBlock
{
}

class AddToDocBlockTest extends \PHPUnit\Framework\TestCase
{
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

/**
 * This is here
 * @see \Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture\AddToDocBlockTest
 */
class AddToDocBlock
{
}

class AddToDocBlockTest extends \PHPUnit\Framework\TestCase
{
}

?>
