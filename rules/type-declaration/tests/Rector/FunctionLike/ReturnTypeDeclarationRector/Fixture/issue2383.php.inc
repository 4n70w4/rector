<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class Issus2383
{
    public function go(): ?UriInterface
    {
        if (rand()) {
            return new UriImplementation();
        }

        return null;
    }
}

interface UriInterface
{

}

class UriImplementation implements UriInterface
{

}