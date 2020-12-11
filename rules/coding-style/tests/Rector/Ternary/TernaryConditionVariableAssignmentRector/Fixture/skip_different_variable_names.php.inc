<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

function skip_different_variable_names($value)
{
    $value ? $a = 1 : $b = 0;
}
