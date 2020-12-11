<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SkipShifted
{
    public function run(string $name, $candidateNames)
    {
        $bareName = $name;
        $prefixes = ['main', 'default'];

        while (in_array($name, $candidateNames, true)) {
            $name = array_shift($prefixes) . ucfirst($bareName);
        }

        return $name;
    }
}
