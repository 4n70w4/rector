<?php

namespace Rector\TypeDeclaration\Tests\Rector\FunctionLike\ReturnTypeDeclarationRector\Fixture;

class This
{
    /**
     * @return $this
     */
    function someFunction($param, $param2)
    {
        return $param;
    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\FunctionLike\ReturnTypeDeclarationRector\Fixture;

class This
{
    /**
     * @return $this
     */
    function someFunction($param, $param2): self
    {
        return $param;
    }
}

?>
