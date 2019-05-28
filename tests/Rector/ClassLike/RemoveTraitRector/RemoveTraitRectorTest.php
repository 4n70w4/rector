<?php declare(strict_types=1);

namespace Rector\Tests\Rector\ClassLike\RemoveTraitRector;

use Rector\Rector\ClassLike\RemoveTraitRector;
use Rector\Testing\PHPUnit\AbstractRectorTestCase;
use Rector\Tests\Rector\ClassLike\RemoveTraitRector\Source\TraitToBeRemoved;

final class RemoveTraitRectorTest extends AbstractRectorTestCase
{
    public function test(): void
    {
        $this->doTestFiles([__DIR__ . '/Fixture/fixture.php.inc']);
    }

    /**
     * @return mixed[]
     */
    protected function getRectorsWithConfiguration(): array
    {
        return [
            RemoveTraitRector::class => [
                '$traitsToRemove' => [TraitToBeRemoved::class],
            ],
        ];
    }
}
