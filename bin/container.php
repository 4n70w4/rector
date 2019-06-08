<?php declare(strict_types=1);

use Rector\Console\Option\LevelOptionResolver;
use Rector\HttpKernel\RectorKernel;
use Symfony\Component\Console\Input\ArgvInput;
use Symplify\PackageBuilder\Configuration\ConfigFileFinder;
use Symplify\PackageBuilder\Console\Input\InputDetector;
use Symplify\PackageBuilder\Console\ShellCode;
use Symplify\PackageBuilder\Console\Style\SymfonyStyleFactory;
use Symplify\PackageBuilder\Exception\Configuration\LevelNotFoundException;

$configFiles = [];

// Detect configuration from --level
try {
    $configFiles[] = (new LevelOptionResolver())->detectFromInputAndDirectory(
        new ArgvInput(),
        __DIR__ . '/../config/set'
    );
} catch (LevelNotFoundException $levelNotFoundException) {
    $symfonyStyle = (new SymfonyStyleFactory())->create();
    $symfonyStyle->error($levelNotFoundException->getMessage());
    exit(ShellCode::ERROR);
}

// And from --config or default one
ConfigFileFinder::detectFromInput('rector', new ArgvInput());
$configFiles[] = ConfigFileFinder::provide('rector', ['rector.yml', 'rector.yaml']);

// remove empty values
$configFiles = array_filter($configFiles);

// 3. Build DI container

// to override the configs without clearing cache
$environment = 'prod' . random_int(1, 10000000);
$rectorKernel = new RectorKernel($environment, InputDetector::isDebug());
if ($configFiles) {
    $rectorKernel->setConfigs($configFiles);
}
$rectorKernel->boot();

return $rectorKernel->getContainer();
