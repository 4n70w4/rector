<?php

namespace Rector\TypeDeclaration\Tests\Rector\FunctionLike\ReturnTypeDeclarationRector\Fixture;

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
