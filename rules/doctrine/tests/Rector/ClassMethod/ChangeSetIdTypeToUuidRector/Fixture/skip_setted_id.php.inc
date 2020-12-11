<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

use Doctrine\ORM\Mapping as ORM;
use Ramsey\Uuid\UuidInterface;

/**
 * @ORM\Entity
 */
class SkipSettedId
{
    private $id;

    public function setId(UuidInterface $uuid): int
    {
        return $this->id = $uuid;
    }
}
