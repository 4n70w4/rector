<?php declare(strict_types=1);

namespace Rector\Tests\Rector\Interface_\RemoveInterfacesRector;

use Rector\Rector\Interface_\RemoveInterfacesRector;
use Rector\Testing\PHPUnit\AbstractRectorTestCase;
use Rector\Tests\Rector\Interface_\RemoveInterfacesRector\Source\SomeInterface;

final class RemoveInterfacesRectorTest extends AbstractRectorTestCase
{
    public function test(): void
    {
        $this->doTestFiles([__DIR__ . '/Fixture/fixture.php.inc', __DIR__ . '/Fixture/fixture2.php.inc']);
    }

    /**
     * @return mixed[]
     */
    protected function getRectorsWithConfiguration(): array
    {
        return [RemoveInterfacesRector::class => [
            '$interfacesToRemove' => [SomeInterface::class],
        ]];
    }
}
