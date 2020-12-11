<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

function skip_ternary_with_variable_assignment($value)
{
    $x = $value ? $a = 1 : $a = 0;
}
