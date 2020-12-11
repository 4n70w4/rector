<?php

namespace Rector\Solid\Tests\Rector\ClassMethod\UseInterfaceOverImplementationInConstructorRector\Fixture;

class SkipSimpleType
{
    public function __construct(int $someImplementation)
    {
    }
}
