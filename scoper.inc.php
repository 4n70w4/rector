<?php declare(strict_types=1);

require_once __DIR__ . '/vendor/autoload.php';

use Isolated\Symfony\Component\Finder\Finder;
use Nette\Loaders\RobotLoader;
use Nette\Utils\Strings;

// whitelist all "Rector\*" classes, so they're not prefixed and people can use them in .yml configs and extends
// before this gets solved: https://github.com/humbug/php-scoper/issues/192#issuecomment-382157399
$robotLoader = new RobotLoader();
$robotLoader->addDirectory(__DIR__ . '/src');
$robotLoader->addDirectory(__DIR__ . '/packages');
$robotLoader->excludeDirectory('*tests*');
$robotLoader->rebuild();

$whitelistedRectorClasses = [];
foreach ($robotLoader->getIndexedClasses() as $class => $file) {
    if (Strings::startsWith($class, 'Rector')) {
        $whitelistedRectorClasses[] = $class;
    }
}

return [
    'prefix' => 'RectorPrefixed',
    'finders' => [
        Finder::create()
            ->files()
            ->ignoreVCS(true)
            // ↓ this is regex!
            ->notName('#LICENSE|.*\\.md|.*\\.dist|Makefile|composer\\.json|composer\\.lock|.*\\.sh#')
            ->in(__DIR__ .'/bin')
            ->in(__DIR__ .'/config')
            ->in(__DIR__ .'/packages')
            ->in(__DIR__ .'/src')
            ->in(__DIR__ .'/vendor')
            ->exclude([
                'docs',
                'Tests',
                'tests',
                'Test',
                'test'
            ])
            // Could not scan for classes inside "/var/www/rector/build/vendor/friendsofphp/php-cs-fixer/tests/Test/AbstractFixerTestCase.php" which does not appear to be a file nor a folder

        ,
        // to make "composer dump" work
        Finder::create()->append([
            'composer.json',
        ])
    ],
    'whitelist' => $whitelistedRectorClasses,
    'patchers' => [
        function (string $filePath, string $prefix, string $contents): string {
            // Change the contents here.
            return $contents;
        },
    ],
];

## Extra notes
// composer.json: "find build/ -type f | xargs sed -i 's/use Symfony/use RectorPrefixed\\\\\\\\Symfony/g'" is needed for:
// https://github.com/symfony/symfony/blob/226e2f3949c5843b67826aca4839c2c6b95743cf/src/Symfony/Component/DependencyInjection/Dumper/PhpDumper.php#L897
