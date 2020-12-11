<?php

namespace Rector\Php70\Tests\Rector\StaticCall\StaticCallOnNonStaticToInstanceCallRector\Fixture;

abstract class ParentStatic
{
    public static function doWork()
    {
    }
}

class KeepParentStatic
{
}

class EndUser
{
    public function run()
    {
        ChildStatic::doWork();
    }
}
