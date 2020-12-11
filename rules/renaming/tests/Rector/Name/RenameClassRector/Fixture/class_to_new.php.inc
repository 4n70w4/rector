<?php

namespace Rector\Renaming\Tests\Rector\Name\RenameClassRector\Fixture;

class ClassToNew
{
    // ...
}

?>
-----
<?php

namespace Rector\Renaming\Tests\Rector\Name\RenameClassRector\Fixture;

class MyCustomValidatorTest extends \Rector\Renaming\Tests\Rector\Name\RenameClassRector\Fixture\Source\NewClass
{
    // ...
}

?>
