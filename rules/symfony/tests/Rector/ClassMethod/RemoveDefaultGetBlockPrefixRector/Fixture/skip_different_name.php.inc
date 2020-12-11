<?php

namespace Rector\Symfony\Tests\Rector\ClassMethod\RemoveDefaultGetBlockPrefixRector\Fixture;

use Symfony\Component\Form\AbstractType;

class SkipDifferentName
{
    public function getBlockPrefix()
    {
        return 'unique';
    }
}
