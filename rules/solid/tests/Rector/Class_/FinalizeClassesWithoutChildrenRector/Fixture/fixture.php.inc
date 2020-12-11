<?php

namespace Rector\Solid\Tests\Rector\Class_\FinalizeClassesWithoutChildrenRector\Fixture;

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

namespace Rector\Solid\Tests\Rector\Class_\FinalizeClassesWithoutChildrenRector\Fixture;

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
