<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

use Rector\SOLID\Tests\Rector\ClassMethod\UseInterfaceOverImplementationInConstructorRector\Source\Orange;

class SkipClassThatImplementsInterfaceWithMultipleChildren
{
    public function __construct(Orange $someImplementation)
    {
    }
}
