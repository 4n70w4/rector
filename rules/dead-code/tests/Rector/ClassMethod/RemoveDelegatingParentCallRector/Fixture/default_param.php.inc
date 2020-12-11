<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;
Class Base
{
    public function __construct($a, $b = null)
    {
    }
}

class Override extends Base
{
    public function __construct($a)
    {
        parent::__construct($a);
    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;
Class Base
{
    public function __construct($a, $b = null)
    {
    }
}

class Override extends Base
{
}

?>
