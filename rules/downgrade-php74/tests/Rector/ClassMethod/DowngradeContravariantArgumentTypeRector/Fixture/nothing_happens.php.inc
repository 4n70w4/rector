<?php

namespace Rector\DowngradePhp74\Tests\Rector\ClassMethod\DowngradeContravariantArgumentTypeRector\Fixture;

class NothingHappens
{
    public function contraVariantArguments(NothingHappensType $type)
    { /* … */ }
}

class NothingHappensB extends NothingHappensA
{
    public function contraVariantArguments(NothingHappensType $type)
    { /* … */ }
}

?>
