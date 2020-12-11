<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

use Rector\SOLID\Tests\Rector\Class_\ChangeReadOnlyVariableWithDefaultValueToConstantRector\Source\ReferenceInConstructor;

class SkipReferencedInConstructor
{
    public function run()
    {
        $value = 'name';
        $servicesConfigurator = new ReferenceInConstructor($value);
    }
}
