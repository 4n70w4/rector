<?php

namespace Rector\TypeDeclaration\Tests\Rector\FunctionLike\ParamTypeDeclarationRector\Fixture\nikic;

/**
 * @param int $a
 * @param int $b
 * @return int
 */
function add2($a, $b) {
    return $a + $b;
}

class Basic {
    /**
     * @param int $a
     * @param int $b
     * @return int
     */
    public function add2($a, $b) {
        return $a + $b;
    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\FunctionLike\ParamTypeDeclarationRector\Fixture\nikic;

/**
 * @param int $a
 * @param int $b
 * @return int
 */
function add2(int $a, int $b) {
    return $a + $b;
}

class Basic {
    /**
     * @param int $a
     * @param int $b
     * @return int
     */
    public function add2(int $a, int $b) {
        return $a + $b;
    }
}

?>
