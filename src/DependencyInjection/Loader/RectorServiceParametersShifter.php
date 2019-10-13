<?php

declare(strict_types=1);

namespace Rector\DependencyInjection\Loader;

use Nette\Utils\Strings;
use Rector\Exception\Configuration\InvalidConfigurationException;
use Rector\Exception\ShouldNotHappenException;
use ReflectionClass;
use Symfony\Component\DependencyInjection\Loader\YamlFileLoader;
use Symfony\Component\Yaml\Yaml;

/**
 * Before:
 *
 * services:
 *     SomeRector:
 *         key: value
 *
 * After:
 *
 * services:
 *     SomeRector:
 *         $onlyParameterToConfigure:
 *             key: value
 */
final class RectorServiceParametersShifter
{
    /**
     * @var string
     */
    private const SERVICES_KEY = 'services';

    /**
     * @var string[]
     */
    private $serviceKeywords = [];

    public function __construct()
    {
        $this->serviceKeywords = (new ReflectionClass(YamlFileLoader::class))->getStaticProperties()['serviceKeywords'];
    }

    /**
     * @param mixed[] $configuration
     * @return mixed[]
     */
    public function process(array $configuration, string $file): array
    {
        if (! isset($configuration[self::SERVICES_KEY]) || ! is_array($configuration[self::SERVICES_KEY])) {
            return $configuration;
        }

        $configuration[self::SERVICES_KEY] = $this->processServices($configuration[self::SERVICES_KEY], $file);

        return $configuration;
    }

    /**
     * @param mixed[] $services
     * @return mixed[]
     */
    private function processServices(array $services, string $file): array
    {
        foreach ($services as $serviceName => $serviceDefinition) {
            if (! $this->isRectorClass($serviceName) || empty($serviceDefinition)) {
                continue;
            }

            if (! is_array($serviceDefinition)) {
                throw new ShouldNotHappenException(sprintf(
                    'Rector rule "%s" has invalid configuration in "%s". Fix it to an array',
                    $serviceName,
                    $file
                ));
            }

            $nonReservedNonVariables = $this->resolveRectorConfiguration($serviceDefinition);

            // nothing to change
            if (count($nonReservedNonVariables) === 0) {
                continue;
            }

            $arrayParameterNames = $this->resolveArrayConstructorArgumentNames($serviceName);

            // we can autowire exclusively 1 parameter only
            if (count($arrayParameterNames) !== 1) {
                throw new InvalidConfigurationException(sprintf(
                    'There must be array argument in "%s" constructor or explicit $argument name in configuration:%s%s',
                    $serviceName,
                    PHP_EOL . PHP_EOL,
                    Yaml::dump($serviceDefinition, Yaml::DUMP_OBJECT_AS_MAP)
                ));
            }

            $serviceDefinition['arguments']['$' . $arrayParameterNames[0]] = $nonReservedNonVariables;

            // cleanup parameters
            foreach (array_keys($nonReservedNonVariables) as $key) {
                unset($serviceDefinition[$key]);
            }

            $services[$serviceName] = $serviceDefinition;
        }

        return $services;
    }

    private function isRectorClass(string $serviceName): bool
    {
        return Strings::endsWith($serviceName, 'Rector');
    }

    /**
     * @param mixed[] $serviceDefinition
     * @return mixed[]
     */
    private function resolveRectorConfiguration(array $serviceDefinition): array
    {
        $configuration = [];

        foreach ($serviceDefinition as $key => $value) {
            if ($this->isReservedKey($key)) {
                continue;
            }

            // is argument name
            if (Strings::startsWith($key, '$')) {
                continue;
            }

            $configuration[$key] = $value;
        }

        return $configuration;
    }

    /**
     * @return string[]
     */
    private function resolveArrayConstructorArgumentNames(string $serviceName): array
    {
        $constructorMethodReflection = (new ReflectionClass($serviceName))->getConstructor();
        if ($constructorMethodReflection === null) {
            return [];
        }

        $arrayParameters = [];
        foreach ($constructorMethodReflection->getParameters() as $reflectionParameter) {
            if (! $reflectionParameter->isArray()) {
                continue;
            }

            $arrayParameters[] = $reflectionParameter->getName();
        }

        return $arrayParameters;
    }

    /**
     * @param string|int|bool $key
     */
    private function isReservedKey($key): bool
    {
        if (! is_string($key)) {
            return false;
        }

        return in_array($key, $this->serviceKeywords, true);
    }
}
