<?php

namespace Rector\SymfonyPHPUnit\Tests\Rector\Class_\SelfContainerGetMethodCallFromTestToSetUpMethodRector\Fixture;

use Rector\SymfonyPHPUnit\Tests\Rector\Class_\SelfContainerGetMethodCallFromTestToSetUpMethodRector\Source\ParentClassWithPropertyKernelTestCase;
use Symfony\Component\HttpFoundation\Session\SessionInterface;

class SkipSessions
{
    public function testOne()
    {
        $firstSession = self::$container->get(SessionInterface::class);
        $firstSession->doStuff();
    }

    public function testTwo()
    {
        $secondSession = self::$container->get(SessionInterface::class);
        $secondSession->doAnotherStuff();
    }
}
