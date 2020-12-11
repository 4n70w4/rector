<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

use Rector\SOLID\Tests\Rector\ClassMethod\UseInterfaceOverImplementationInConstructorRector\Source\ClassThatImplementsMoreInterfaces;

class SkipMultipleInterfaces
{
    public function __construct(ClassThatImplementsMoreInterfaces $someImplementation)
    {
    }
}
