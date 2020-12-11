<?php

namespace Rector\Renaming\Tests\Rector\Name\RenameClassRector\Fixture;

trait MyTrait
{
}

?>
-----
<?php

namespace MyNewNamespace;

trait MyNewTrait
{
}

?>
