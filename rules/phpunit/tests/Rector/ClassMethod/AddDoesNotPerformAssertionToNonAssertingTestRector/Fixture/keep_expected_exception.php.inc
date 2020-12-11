<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

use InvalidArgumentException;

class KeepExpectedException extends \PHPUnit\Framework\TestCase
{
    /**
     * @expectedException \Exception
     */
    public function test()
    {
    }

    public function testExpectException()
    {
        $this->expectException('Throwable');
        throw new InvalidArgumentException();
    }

    public function testSetExpectedException()
    {
        $this->setExpectedException('Throwable');
    }
}
