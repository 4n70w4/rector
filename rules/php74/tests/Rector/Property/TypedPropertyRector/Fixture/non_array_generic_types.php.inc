<?php

namespace Rector\Php74\Tests\Rector\Property\TypedPropertyRector\Fixture;

class NonArrayGenericTypes
{
}

class Foo
{
}

final class NonArrayGenericTypes
{
    /**
     * @var \Traversable<int, string>
     */
    private $foo;

    /**
     * @var NonArrayGenericTypes<Foo>
     */
    private $bar;
}

?>
-----
<?php

namespace Rector\Php74\Tests\Rector\Property\TypedPropertyRector\Fixture;

class NonArrayGenericTypes
{
}

class Foo
{
}

final class NonArrayGenericTypes
{
    /**
     * @var \Traversable<int, string>
     */
    private \Traversable $foo;

    /**
     * @var NonArrayGenericTypes<Foo>
     */
    private \Rector\Php74\Tests\Rector\Property\TypedPropertyRector\Fixture\NonArrayGenericTypes $bar;
}

?>
