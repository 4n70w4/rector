<?php

namespace Rector\DowngradePhp74\Tests\Rector\ClassMethod\DowngradeContravariantArgumentTypeRector\Fixture;

class GapLevelInterface
{
    public function contraVariantArguments(GapLevelInterfaceChildType $type);
}

interface GapLevelInterfaceB extends GapLevelInterfaceA
{
}

interface GapLevelInterfaceC extends GapLevelInterfaceB
{
    public function contraVariantArguments(GapLevelInterfaceParentType $type);
}

?>
-----
<?php

namespace Rector\DowngradePhp74\Tests\Rector\ClassMethod\DowngradeContravariantArgumentTypeRector\Fixture;

class GapLevelInterface
{
    public function contraVariantArguments(GapLevelInterfaceChildType $type);
}

interface GapLevelInterfaceB extends GapLevelInterfaceA
{
}

interface GapLevelInterfaceC extends GapLevelInterfaceB
{
    /**
     * @param \Rector\DowngradePhp74\Tests\Rector\ClassMethod\DowngradeContravariantArgumentTypeRector\Fixture\GapLevelInterfaceParentType $type
     */
    public function contraVariantArguments($type);
}

?>
