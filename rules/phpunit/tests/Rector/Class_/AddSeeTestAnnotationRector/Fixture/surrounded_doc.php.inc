<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

/**
 * @doto àreprendre et refactorer
 */
class SurroundedDoc
{
}

class SurroundedDocTest extends \PHPUnit\Framework\TestCase
{
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

/**
 * @doto àreprendre et refactorer
 * @see \Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture\SurroundedDocTest
 */
class SurroundedDoc
{
}

class SurroundedDocTest extends \PHPUnit\Framework\TestCase
{
}

?>
