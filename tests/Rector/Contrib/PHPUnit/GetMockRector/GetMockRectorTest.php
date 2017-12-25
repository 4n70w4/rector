<?php declare(strict_types=1);

namespace Rector\Tests\Rector\Contrib\PHPUnit\GetMockRector;

use Rector\Rector\Contrib\PHPUnit\GetMockRector;
use Rector\Testing\PHPUnit\AbstractRectorTestCase;

final class GetMockRectorTest extends AbstractRectorTestCase
{
    public function test(): void
    {
        $this->doTestFileMatchesExpectedContent(
            __DIR__ . '/Wrong/wrong.php.inc',
            __DIR__ . '/Correct/correct.php.inc'
        );
    }

    /**
     * @return string[]
     */
    protected function getRectorClasses(): array
    {
        return [GetMockRector::class];
    }
}
