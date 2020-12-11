<?php

namespace Rector\DowngradePhp74\Tests\Rector\ClassMethod\DowngradeCovariantReturnTypeRector\Fixture;

class SameClassButQualifiedAndNot
{
    public function covariantReturnTypes(): \Rector\DowngradePhp74\Tests\Rector\ClassMethod\DowngradeCovariantReturnTypeRector\Fixture\SameButDifferentParentType
    { /* … */ }
}

class SameButDifferentB extends SameButDifferentA
{
    public function covariantReturnTypes(): SameButDifferentParentType
    { /* … */ }
}

class SameButDifferentC extends SameButDifferentB
{
    public function covariantReturnTypes(): \Rector\DowngradePhp74\Tests\Rector\ClassMethod\DowngradeCovariantReturnTypeRector\Fixture\SameButDifferentParentType
    { /* … */ }
}

?>
