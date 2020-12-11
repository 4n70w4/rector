<?php

namespace Rector\Privatization\Tests\Rector\ClassConst\PrivatizeLocalClassConstantRector\Fixture;

class Protected
{
    const CHILD_ONLY = true;
}

class ConstantUser extends Protected
{
    public function run()
    {
        $is = self::CHILD_ONLY;
        $isAgain = parent::CHILD_ONLY;

        return static::CHILD_ONLY;
    }
}

?>
-----
<?php

namespace Rector\Privatization\Tests\Rector\ClassConst\PrivatizeLocalClassConstantRector\Fixture;

class Protected
{
    protected const CHILD_ONLY = true;
}

class ConstantUser extends Protected
{
    public function run()
    {
        $is = self::CHILD_ONLY;
        $isAgain = parent::CHILD_ONLY;

        return static::CHILD_ONLY;
    }
}

?>
