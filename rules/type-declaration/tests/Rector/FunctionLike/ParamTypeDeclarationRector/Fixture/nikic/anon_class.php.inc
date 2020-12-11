<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

new class {
    /** @param int $a */
    public function test($a) {}
};

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

new class {
    /** @param int $a */
    public function test(int $a) {}
};

?>
