<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

use Doctrine\ORM\Mapping as ORM;

class DoctrineRelationTargetEntitySameNamespace
{
}

class DoctrineRelationTargetEntitySameNamespace
{
    /**
     * @ORM\OneToOne(targetEntity="DoctrineRelationTargetEntitySameNamespace")
     */
    private $related;
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

use Doctrine\ORM\Mapping as ORM;

class DoctrineRelationTargetEntitySameNamespace
{
}

class DoctrineRelationTargetEntitySameNamespace
{
    /**
     * @ORM\OneToOne(targetEntity="DoctrineRelationTargetEntitySameNamespace")
     * @var \Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture\DoctrineRelationTargetEntitySameNamespace|null
     */
    private $related;
}

?>
