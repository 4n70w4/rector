<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SkipPartOfAnotherConstant
{
    public const TREE_OF_VALUES = [
        'firstValue' => 'string',
        'seocnd' => 'string',
        'thirdValue' => 'string',
    ];
}
