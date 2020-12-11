<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class FirstClass
{
}

class SecondClass
{
}

class ThirdClass extends SecondClass
{
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

final class FirstClass
{
}

class SecondClass
{
}

final class ThirdClass extends SecondClass
{
}

?>
