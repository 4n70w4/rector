<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

function skip_variable_variables_with_braces($value)
{
    ${$value} = true;
}
