<?php

declare(strict_types=1);

use Rector\Core\Configuration\Option;
use Rector\Set\ValueObject\DowngradeSetList;
use Symfony\Component\DependencyInjection\Loader\Configurator\ContainerConfigurator;

require __DIR__ . '/configuration.php';

return static function (ContainerConfigurator $containerConfigurator): void {
    $parameters = $containerConfigurator->parameters();

    $parameters->set(Option::SKIP, DowngradeRectorConfig::RECTOR_EXCLUDE_PATHS);

    $parameters->set(Option::SETS, [
        DowngradeSetList::PHP_80,
        DowngradeSetList::PHP_74,
        DowngradeSetList::PHP_73,
    ]);
};
