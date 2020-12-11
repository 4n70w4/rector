<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

final class SkipBuildMockTest extends \PHPUnit\Framework\TestCase
{
    public function test()
    {
        $secondMock = $this->buildMock()
            ->getMock();
    }
}
