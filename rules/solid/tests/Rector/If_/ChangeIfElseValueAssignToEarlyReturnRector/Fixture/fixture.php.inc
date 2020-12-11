<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SomeClass
{
    public function run()
    {
        if ($this->hasDocBlock($tokens, $index)) {
            $docToken = $tokens[$this->getDocBlockIndex($tokens, $index)];
        } else {
            $docToken = null;
        }

        return $docToken;
    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SomeClass
{
    public function run()
    {
        if ($this->hasDocBlock($tokens, $index)) {
            return $tokens[$this->getDocBlockIndex($tokens, $index)];
        }

        return null;
    }
}

?>
