<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

/**
 * @template T
 */
abstract class TestClassStringType
{
    /**
     * @return class-string<T>
     */
    abstract protected function getClassStringForT(): string;
}
