<?php

namespace Rector\TypeDeclaration\Tests\Rector\FunctionLike\ParamTypeDeclarationRector\Fixture\nikic;

new class {
    /** @param int $a */
    public function test($a) {}
};

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\FunctionLike\ParamTypeDeclarationRector\Fixture\nikic;

new class {
    /** @param int $a */
    public function test(int $a) {}
};

?>
