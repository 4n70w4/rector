<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

function skip_global_variable_variables_with_braces($foo)
{
    global ${$foo->bar};
}
