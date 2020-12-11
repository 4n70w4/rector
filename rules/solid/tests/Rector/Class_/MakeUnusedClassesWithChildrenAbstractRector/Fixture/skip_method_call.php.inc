<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SkipMethodCall
{
    public static function run()
    {

    }
}

class ClassCalling
{
    public function go($skipMethodCall)
    {
        /** @var SkipMethodCall $skipMethodCall */
        $skipMethodCall->run();
    }
}

function localFunction()
{
    // just so the ClassCalling is not made abstract
    $classCalling = new ClassCalling();
}
