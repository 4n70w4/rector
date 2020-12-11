<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

function iterableFunction($value)
{
    yield 1;
    yield 2;
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

function iterableFunction($value): iterable
{
    yield 1;
    yield 2;
}

?>
