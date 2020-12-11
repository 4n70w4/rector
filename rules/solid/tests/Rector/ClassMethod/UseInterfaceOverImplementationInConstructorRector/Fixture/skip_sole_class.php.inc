<?php

namespace Rector\Solid\Tests\Rector\ClassMethod\UseInterfaceOverImplementationInConstructorRector\Fixture;

class SkipSoleClass
{
    public function __construct(NoInterface $someImplementation)
    {
    }
}

class NoInterface
{
}