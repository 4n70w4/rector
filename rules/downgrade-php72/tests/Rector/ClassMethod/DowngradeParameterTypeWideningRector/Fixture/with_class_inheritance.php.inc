<?php

namespace Rector\DowngradePhp72\Tests\Rector\ClassMethod\DowngradeParameterTypeWideningRector\Fixture;

class WithClassInheritance
{
    public function test(array $input)
    {
        /* ... */
    }
}

class ChildClass extends WithClassInheritance
{
    public function test($input) // type omitted for $input
    {
        /* ... */
    }
}

class AffectedChildClass extends WithClassInheritance
{
    public function test(array $input)
    {
        /* ... */
    }
}

?>
-----
<?php

namespace Rector\DowngradePhp72\Tests\Rector\ClassMethod\DowngradeParameterTypeWideningRector\Fixture;

class WithClassInheritance
{
    /**
     * @param mixed[] $input
     */
    public function test($input)
    {
        /* ... */
    }
}

class ChildClass extends WithClassInheritance
{
    public function test($input) // type omitted for $input
    {
        /* ... */
    }
}

class AffectedChildClass extends WithClassInheritance
{
    /**
     * @param mixed[] $input
     */
    public function test($input)
    {
        /* ... */
    }
}

?>
