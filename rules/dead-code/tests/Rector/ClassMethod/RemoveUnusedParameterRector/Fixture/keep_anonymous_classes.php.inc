<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;
    }
}

namespace Rector\DeadCode\Tests\Rector\ClassMethod\RemoveUnusedParameterRector\Fixture
{
    use Rector\DeadCode\Tests\Rector\ClassMethod\RemoveUnusedParameterRector\FixtureInterface\Foo;

    class Baz
    {
        public function test()
        {
            $class = new class implements Foo
            {
                public function bar($value1)
                {
                }
            };
        }
    }
}
