<?php

namespace Rector\Renaming\Tests\Rector\Name\RenameClassRector\Fixture;

class ClassToInterface
{
    public function run(\DateTime $dateTime): \DateTime
    {
        $oldClassWithTypo = new \DateTime();
    }
}

?>
-----
<?php

namespace Rector\Renaming\Tests\Rector\Name\RenameClassRector\Fixture;

class ClassToInterface
{
    public function run(\DateTimeInterface $dateTime): \DateTimeInterface
    {
        $oldClassWithTypo = new \DateTime();
    }
}

?>
