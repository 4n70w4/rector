<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SkipSelf
{
    public function getSelf(): self
    {
        return new self();
    }
}
