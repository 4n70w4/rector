<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SomeClass
{
    public function run()
    {
        // condition 1
        if ($cond1) {
            // condition 2
            if ($cond2) {
                return 'foo';
            }
        }

        /** condition 1 */
        if ($cond1) {
            /** condition 2 */
            if ($cond2) {
                return 'foo';
            }
        }
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
        // condition 1
        // condition 2
        if ($cond1 && $cond2) {
            return 'foo';
        }

        /** condition 1 */
        /** condition 2 */
        if ($cond1 && $cond2) {
            return 'foo';
        }
    }
}

?>
