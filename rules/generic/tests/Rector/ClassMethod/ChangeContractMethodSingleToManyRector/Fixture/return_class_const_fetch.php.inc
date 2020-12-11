<?php

namespace Rector\Generic\Tests\Rector\ClassMethod\ChangeContractMethodSingleToManyRector\Fixture;

use Rector\Generic\Tests\Rector\ClassMethod\ChangeContractMethodSingleToManyRector\Source\OneToManyInterface;

class ReturnClassConstFetch
{
    public function getNode(): string
    {
        return self::class;
    }
}

?>
-----
<?php

namespace Rector\Generic\Tests\Rector\ClassMethod\ChangeContractMethodSingleToManyRector\Fixture;

use Rector\Generic\Tests\Rector\ClassMethod\ChangeContractMethodSingleToManyRector\Source\OneToManyInterface;

class ReturnClassConstFetch
{
    /**
     * @return string[]
     */
    public function getNodes(): array
    {
        return [self::class];
    }
}

?>
