<?php

namespace Rector\PHPUnit\Tests\Rector\MethodCall\RemoveExpectAnyFromMockRector\Fixture;

use PHPUnit\Framework\TestCase;

class Fixture
{
    public function test()
    {
        $translator = $this->createMock('SomeClass');
        $translator->expects($this->any())
            ->method('trans')
            ->willReturn('translated max {{ max }}!');
    }
}

?>
-----
<?php

namespace Rector\PHPUnit\Tests\Rector\MethodCall\RemoveExpectAnyFromMockRector\Fixture;

use PHPUnit\Framework\TestCase;

class Fixture
{
    public function test()
    {
        $translator = $this->createMock('SomeClass');
        $translator
            ->method('trans')
            ->willReturn('translated max {{ max }}!');
    }
}

?>
