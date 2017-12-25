<?php declare(strict_types=1);

namespace Rector\Tests\Rector\Dynamic\ClassReplacerRector;

use Rector\Rector\Dynamic\ClassReplacerRector;
use Rector\Testing\PHPUnit\AbstractConfigurableRectorTestCase;

final class ClassReplacerRectorTest extends AbstractConfigurableRectorTestCase
{
    public function test(): void
    {
        $this->doTestFileMatchesExpectedContent(
            __DIR__ . '/wrong/wrong.php.inc',
            __DIR__ . '/correct/correct.php.inc'
        );

        $this->doTestFileMatchesExpectedContent(
            __DIR__ . '/wrong/wrong2.php.inc',
            __DIR__ . '/correct/correct2.php.inc'
        );

        $this->doTestFileMatchesExpectedContent(
            __DIR__ . '/wrong/wrong3.php.inc',
            __DIR__ . '/correct/correct3.php.inc'
        );
    }

    protected function provideConfig(): string
    {
        return __DIR__ . '/config/rector.yml';
    }

    /**
     * @return string[]
     */
    protected function getRectorClasses(): array
    {
        return [ClassReplacerRector::class];
    }
}
