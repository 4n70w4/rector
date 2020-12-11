<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class FunctionForeachContinue
{
    public function run($list, $flag)
    {
        function ($list) use ($flag) {
            foreach ($list as $key => $val) {
                if ($flag && empty($key)) {
                    continue;
                } elseif (empty($val)) {
                    $val = $key;
                }
            }
        };
    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class FunctionForeachContinue
{
    public function run($list, $flag)
    {
        function ($list) use ($flag) {
            foreach ($list as $key => $val) {
                if ($flag && empty($key)) {
                    continue;
                }
                if (empty($val)) {
                    $val = $key;
                }
            }
        };
    }
}

?>
