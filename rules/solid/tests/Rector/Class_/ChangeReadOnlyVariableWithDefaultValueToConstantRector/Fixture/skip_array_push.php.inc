<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

final class SkipArrayPush
{
    public function run(): string
    {
        $sortedNodes = [];
        array_push($sortedNodes, 1);

        return $sortedNodes;
    }
}
