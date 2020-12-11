<?php

namespace Rector\TypeDeclaration\Tests\Rector\FunctionLike\ReturnTypeDeclarationRector\Fixture\nikic;

class Iterable {
    /** @return iterable */
    public function getIterable($value) {
        return $value;
    }
}
class BuildOnThePreviousClass extends Iterable {
    /** @return array */
    public function getIterable($value) {
        return $value;
    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\FunctionLike\ReturnTypeDeclarationRector\Fixture\nikic;

class Iterable {
    public function getIterable($value): iterable {
        return $value;
    }
}
class BuildOnThePreviousClass extends Iterable {
    /** @return array */
    public function getIterable($value): iterable {
        return $value;
    }
}

?>
