<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SkipReferenced
{
    public function run()
    {
        $value = [];
        $this->process($value);
    }

    private function process(array &$value)
    {
    }
}
