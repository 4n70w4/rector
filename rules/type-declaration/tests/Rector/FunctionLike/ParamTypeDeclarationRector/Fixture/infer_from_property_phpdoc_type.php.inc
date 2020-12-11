<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class InferFromPropertyPhpdocType
{
    /**
     * @var int
     */
    private $id;

    public function setId($id)
    {
        $this->id = $id;
    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class InferFromPropertyPhpdocType
{
    /**
     * @var int
     */
    private $id;

    public function setId(int $id)
    {
        $this->id = $id;
    }
}

?>
