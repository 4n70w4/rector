<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SkipAbstractClassRequired extends AbstractClassRequiring
{
    private $name;
    public function setName(string $name): void
    {
        $this->name = $name;
    }
}

abstract class AbstractClassRequiring
{
    protected abstract function setName(string $name);
}
