<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

/** @param \My\Bar $foo */ function my_foo($foo) {}
?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

/** @param \My\Bar $foo */ function my_foo(\My\Bar $foo) {}
?>
