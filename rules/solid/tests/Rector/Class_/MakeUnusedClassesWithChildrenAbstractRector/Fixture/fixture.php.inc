<?php

namespace Rector\Solid\Tests\Rector\Class_\MakeUnusedClassesWithChildrenAbstractRector\Fixture;

class SomeClass extends PossibleAbstractClass
{
}

class PossibleAbstractClass
{
}

?>
-----
<?php

namespace Rector\Solid\Tests\Rector\Class_\MakeUnusedClassesWithChildrenAbstractRector\Fixture;

class SomeClass extends PossibleAbstractClass
{
}

abstract class PossibleAbstractClass
{
}

?>
