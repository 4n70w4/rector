<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SkipMultipleProperties
{
    /**
     * @var string[]
     */
    private $moreMagic, $magicMethods = [
        '__toString',
        '__wakeup',
    ];
}
