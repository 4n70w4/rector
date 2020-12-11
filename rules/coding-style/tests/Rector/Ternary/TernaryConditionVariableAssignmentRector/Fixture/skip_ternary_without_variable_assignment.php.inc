<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

function skip_ternary_without_variable_assignment($value)
{
    $value ? 1 : $a = 0;
}
