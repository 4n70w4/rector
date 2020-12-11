<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SkipStaticCall
{
    public static function run()
    {

    }
}

function run()
{
    SkipStaticCall::run();
}
