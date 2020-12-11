<?php

namespace Rector\SOLID\Tests\Rector\Class_\FinalizeClassesWithoutChildrenRector\Fixture;

class Fixture
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

namespace Rector\SOLID\Tests\Rector\Class_\FinalizeClassesWithoutChildrenRector\Fixture;

final class Fixture
{
}

class SecondClass
{
}

final class ThirdClass extends SecondClass
{
}

?>
