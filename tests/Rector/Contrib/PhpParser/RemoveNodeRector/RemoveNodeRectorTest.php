<?php declare(strict_types=1);

namespace Rector\Tests\Rector\Contrib\PhpParser\RemoveNodeRector;

use Rector\Rector\Contrib\PhpParser\RemoveNodeRector;
use Rector\Testing\PHPUnit\AbstractRectorTestCase;

final class RemoveNodeRectorTest extends AbstractRectorTestCase
{
    public function test(): void
    {
        $this->doTestFileMatchesExpectedContent(
            __DIR__ . '/Wrong/wrong.php.inc',
            __DIR__ . '/Correct/correct.php.inc'
        );

        $this->doTestFileMatchesExpectedContent(
            __DIR__ . '/Wrong/wrong2.php.inc',
            __DIR__ . '/Correct/correct2.php.inc'
        );
    }

    /**
     * @return string[]
     */
    protected function getRectorClasses(): array
    {
        return [RemoveNodeRector::class];
    }
}
