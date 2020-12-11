<?php

namespace Rector\Renaming\Tests\Rector\Name\RenameClassRector\Fixture;

class MyCustomValidatorTest extends \Rector\Renaming\Tests\Rector\Name\RenameClassRector\Fixture\Source\OldClass
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
