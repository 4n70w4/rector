<?php

namespace Rector\TypeDeclaration\Tests\Rector\ClassMethod\AddParamTypeDeclarationRector\Fixture;

use Rector\TypeDeclaration\Tests\Rector\ClassMethod\AddParamTypeDeclarationRector\Source\ParserInterface;

class Someclassimplementingparserinterface
{
    public function parse($code, \PhpParser\ErrorHandler $errorHandler = null)
    {
    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\ClassMethod\AddParamTypeDeclarationRector\Fixture;

use Rector\TypeDeclaration\Tests\Rector\ClassMethod\AddParamTypeDeclarationRector\Source\ParserInterface;

class Someclassimplementingparserinterface
{
    public function parse(string $code, \PhpParser\ErrorHandler $errorHandler = null)
    {
    }
}

?>
