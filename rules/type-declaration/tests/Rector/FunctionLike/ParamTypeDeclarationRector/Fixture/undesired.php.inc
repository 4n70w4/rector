<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

/**
 * @param real|int $a
 * @param int $b
 * @param int|void $c
 */
function someFunction($a, $b, $c) {
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

/**
 * @param real|int $a
 * @param int $b
 * @param int|void $c
 */
function someFunction($a, int $b, $c) {
}

?>
