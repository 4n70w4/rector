<?php

namespace Rector\Defluent\Tests\Rector\MethodCall\FluentChainMethodCallToNormalMethodCallRector\Fixture;

use Symfony\Component\Console\Command\Command;

class SkipFactoryCall
{
    public function go()
    {
        $this->getApplication()
            ->setAutoExit(true);
    }
}
