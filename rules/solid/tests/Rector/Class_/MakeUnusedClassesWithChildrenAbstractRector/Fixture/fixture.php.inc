<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SomeClass extends PossibleAbstractClass
{
}

class PossibleAbstractClass
{
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SomeClass extends PossibleAbstractClass
{
}

abstract class PossibleAbstractClass
{
}

?>
