<?php

namespace Rector\Privatization\Tests\Rector\ClassConst\PrivatizeLocalClassConstantRector\Fixture;

class ProtectedParentParent
{
    const CHILD_ONLY = true;
}

class SecondParent extends ProtectedParentParent
{
}

final class FirstBorn extends SecondParent
{
    public function run()
    {
        return parent::CHILD_ONLY;
    }
}

?>
-----
<?php

namespace Rector\Privatization\Tests\Rector\ClassConst\PrivatizeLocalClassConstantRector\Fixture;

class ProtectedParentParent
{
    protected const CHILD_ONLY = true;
}

class SecondParent extends ProtectedParentParent
{
}

final class FirstBorn extends SecondParent
{
    public function run()
    {
        return parent::CHILD_ONLY;
    }
}

?>
