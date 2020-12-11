<?php

namespace Rector\Privatization\Tests\Rector\ClassConst\PrivatizeLocalClassConstantRector\Fixture;

class KeepPublic
{
    const NON_LOCAL_ONLY = true;
}

class ForeignConstantAddictUser
{
    public function run()
    {
        return KeepPublic::NON_LOCAL_ONLY;
    }
}

?>
-----
<?php

namespace Rector\Privatization\Tests\Rector\ClassConst\PrivatizeLocalClassConstantRector\Fixture;

class KeepPublic
{
    public const NON_LOCAL_ONLY = true;
}

class ForeignConstantAddictUser
{
    public function run()
    {
        return KeepPublic::NON_LOCAL_ONLY;
    }
}

?>
