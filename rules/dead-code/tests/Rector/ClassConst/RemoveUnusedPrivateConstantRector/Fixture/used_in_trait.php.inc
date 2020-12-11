<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

final class KeepStaticConstant
{
    use aTrait;
    private const SOME_CONSTANT = 5;

}

trait aTrait {
    public function foo(){
        return self::SOME_CONSTANT;
    }
}
