<?php

namespace Rector\DeadCode\Tests\Rector\Class_\RemoveUnusedDoctrineEntityMethodAndPropertyRector\Fixture;

use Doctrine\ORM\Mapping as ORM;
use Doctrine\Common\Collections\ArrayCollection;

/**
 * @ORM\Entity
 */
class SkipDoubleEntityCall
{
    /**
     * @ORM\Column
     */
    private $name;

    public function getName()
    {
        return $this->name;
    }
}

/**
 * @ORM\Entity
 */
class SecondOne
{
    /**
     * @ORM\Column
     */
    private $name;

    public function getName()
    {
        return $this->name;
    }
}

class SkipDoubleEntityCall
{
    public function callOnMe($entity)
    {
        if ($entity instanceof SkipDoubleEntityCall || $entity instanceof SecondOne) {
            $entity->getName();
        }
    }
}
