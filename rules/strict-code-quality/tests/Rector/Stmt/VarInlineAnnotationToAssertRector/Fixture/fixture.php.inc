<?php

namespace Rector\StrictCodeQuality\Tests\Rector\Stmt\VarInlineAnnotationToAssertRector\Fixture;

class Fixture
{
    public function run($value)
    {
        /** @var SpecificClass $value */
        $value->call();
    }
}

class SpecificClass
{
}

?>
-----
<?php

namespace Rector\StrictCodeQuality\Tests\Rector\Stmt\VarInlineAnnotationToAssertRector\Fixture;

class Fixture
{
    public function run($value)
    {
        assert($value instanceof \Rector\StrictCodeQuality\Tests\Rector\Stmt\VarInlineAnnotationToAssertRector\Fixture\SpecificClass);
        $value->call();
    }
}

class SpecificClass
{
}

?>
