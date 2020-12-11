<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

use PHPUnit\Framework\TestCase;
use stdClass;

final class PartialArguments extends TestCase
{
    public function test()
    {
        $objects = [ new stdClass(), new stdClass(), new stdClass() ];
        $this->assertContains(new stdClass(), $objects, 'message', false);
        $this->assertNotContains(new stdClass(), $objects, 'message', false);
    }
}
