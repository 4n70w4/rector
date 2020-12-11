<?php

namespace Rector\DowngradePhp74\Tests\Rector\ClassMethod\DowngradeCovariantReturnTypeRector\Fixture;

class TwoLevelAncestor
{
    public function covariantReturnTypes(): TwoLevelParentType
    { /* … */ }
}

class TwoLevelB extends TwoLevelA
{
    public function covariantReturnTypes(): TwoLevelChildType
    { /* … */ }
}

class TwoLevelC extends TwoLevelB
{
    public function covariantReturnTypes(): TwoLevelChildType
    { /* … */ }
}

?>
-----
<?php

namespace Rector\DowngradePhp74\Tests\Rector\ClassMethod\DowngradeCovariantReturnTypeRector\Fixture;

class TwoLevelAncestor
{
    public function covariantReturnTypes(): TwoLevelParentType
    { /* … */ }
}

class TwoLevelB extends TwoLevelA
{
    /**
     * @return \Rector\DowngradePhp74\Tests\Rector\ClassMethod\DowngradeCovariantReturnTypeRector\Fixture\TwoLevelChildType
     */
    public function covariantReturnTypes(): \Rector\DowngradePhp74\Tests\Rector\ClassMethod\DowngradeCovariantReturnTypeRector\Fixture\TwoLevelParentType
    { /* … */ }
}

class TwoLevelC extends TwoLevelB
{
    /**
     * @return \Rector\DowngradePhp74\Tests\Rector\ClassMethod\DowngradeCovariantReturnTypeRector\Fixture\TwoLevelChildType
     */
    public function covariantReturnTypes(): \Rector\DowngradePhp74\Tests\Rector\ClassMethod\DowngradeCovariantReturnTypeRector\Fixture\TwoLevelParentType
    { /* … */ }
}

?>
