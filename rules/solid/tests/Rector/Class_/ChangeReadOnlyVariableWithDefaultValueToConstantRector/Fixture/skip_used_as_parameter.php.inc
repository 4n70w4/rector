<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SkipUsedAsParameters
{
    public function run($items)
    {
        foreach ($items as $key => $value) {
            if ($value === null) {
                $value = [];
            }

            $this->runSomething($value);
        }
    }

    private function runSomething(?array $value)
    {
    }
}
