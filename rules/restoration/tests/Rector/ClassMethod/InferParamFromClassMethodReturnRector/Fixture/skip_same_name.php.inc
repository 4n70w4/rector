<?php

namespace Rector\Restoration\Tests\Rector\ClassMethod\InferParamFromClassMethodReturnRector\Fixture;

use PhpParser\Node\Scalar\String_;
use Rector\Restoration\Tests\Rector\ClassMethod\InferParamFromClassMethodReturnRector\Source\SomeType;

class SkipSameName
{
    public function getNodeTypes(): array
    {
        return [String_::class];
    }

    public function process(String_ $node)
    {
    }
}
