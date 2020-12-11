<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

/** @param callable $foo */ function my_foo($foo) {}
?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

/** @param callable $foo */ function my_foo(callable $foo) {}
?>
