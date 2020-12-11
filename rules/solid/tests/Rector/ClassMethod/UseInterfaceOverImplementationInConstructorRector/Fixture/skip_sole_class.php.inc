<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SkipSoleClass
{
    public function __construct(NoInterface $someImplementation)
    {
    }
}

class NoInterface
{
}