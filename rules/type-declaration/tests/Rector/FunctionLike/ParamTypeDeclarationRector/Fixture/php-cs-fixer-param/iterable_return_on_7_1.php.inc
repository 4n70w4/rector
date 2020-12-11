<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

/** @param iterable $counter */ function my_foo($counter) {}
?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

/** @param iterable $counter */ function my_foo(iterable $counter) {}
?>
