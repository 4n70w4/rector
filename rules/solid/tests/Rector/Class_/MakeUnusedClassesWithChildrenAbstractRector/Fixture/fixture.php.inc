<?php

namespace Rector\SOLID\Tests\Rector\Class_\MakeUnusedClassesWithChildrenAbstractRector\Fixture;

class Fixture
{
}

class PossibleAbstractClass
{
}

?>
-----
<?php

namespace Rector\SOLID\Tests\Rector\Class_\MakeUnusedClassesWithChildrenAbstractRector\Fixture;

class Fixture
{
}

abstract class PossibleAbstractClass
{
}

?>
