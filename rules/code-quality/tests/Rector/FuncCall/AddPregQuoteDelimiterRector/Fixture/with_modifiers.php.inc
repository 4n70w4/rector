<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SomeClass
{
    public function test($input)
    {
        $patttern1 =  '/' . preg_quote('name'). '/imsxeA';
        $patttern2 =  '#' . preg_quote('name'). '#DSUXJu';
    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SomeClass
{
    public function test($input)
    {
        $patttern1 =  '/' . preg_quote('name', '/'). '/imsxeA';
        $patttern2 =  '#' . preg_quote('name', '#'). '#DSUXJu';
    }
}

?>
