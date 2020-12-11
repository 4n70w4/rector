<?php

use Rector\Generic\Tests\Rector\Name\PseudoNamespaceToNamespaceRector\Source\Keep_This;

class Rector_Generic_Tests_Rector_Name_PseudoNamespaceToNamespaceRector_Fixture_UseStatement
{
    public function run()
    {
        return new Keep_This;
    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

use Rector\Generic\Tests\Rector\Name\PseudoNamespaceToNamespaceRector\Source\Keep_This;
class UseStatement
{
    public function run()
    {
        return new Keep_This;
    }
}
