<?php

namespace Rector\TypeDeclaration\Tests\Rector\FunctionLike\ReturnTypeDeclarationRector\Fixture;

use Rector\Core\Exception\NotImplementedYetException;

abstract class ParentOverride
{
    public function getValue()
    {
        throw new NotImplementedYetException();
    }
}

class ParentOverride
{
    public function getValue()
    {
        return 'string';
    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\FunctionLike\ReturnTypeDeclarationRector\Fixture;

use Rector\Core\Exception\NotImplementedYetException;

abstract class ParentOverride
{
    public function getValue()
    {
        throw new NotImplementedYetException();
    }
}

class ParentOverride
{
    public function getValue(): string
    {
        return 'string';
    }
}

?>
