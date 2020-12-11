<?php

namespace Rector\NetteKdyby\Tests\Rector\ClassMethod\ReplaceMagicEventPropertySubscriberWithEventClassSubscriberRector\Fixture;

use Kdyby\Events\Subscriber;
use Rector\NetteKdyby\Tests\Rector\ClassMethod\ReplaceMagicEventPropertySubscriberWithEventClassSubscriberRector\Source\Tomato;

class Fixture
{
    public $onTomatoBuy;

    public function run(Tomato $tomato, int $userId)
    {
        $this->onTomatoBuy($tomato, $userId);
    }
}

final class ActionLogEventSubscriber implements Subscriber
{
    public function getSubscribedEvents(): array
    {
        return [
            Fixture::class . '::onTomatoBuy' => 'onTomatoBuy',
        ];
    }

    public function onTomatoBuy(Tomato $anotherTomato, int $adminId): void
    {
        $anotherTomato->unwrap();
    }
}

?>
-----
<?php

namespace Rector\NetteKdyby\Tests\Rector\ClassMethod\ReplaceMagicEventPropertySubscriberWithEventClassSubscriberRector\Fixture;

use Kdyby\Events\Subscriber;
use Rector\NetteKdyby\Tests\Rector\ClassMethod\ReplaceMagicEventPropertySubscriberWithEventClassSubscriberRector\Source\Tomato;

class Fixture
{
    public $onTomatoBuy;

    public function run(Tomato $tomato, int $userId)
    {
        $this->onTomatoBuy($tomato, $userId);
    }
}

final class ActionLogEventSubscriber implements Subscriber
{
    public function getSubscribedEvents(): array
    {
        return [
            \Rector\NetteKdyby\Tests\Rector\ClassMethod\ReplaceMagicEventPropertySubscriberWithEventClassSubscriberRector\Fixture\Event\FixtureTomatoBuyEvent::class => 'onTomatoBuy',
        ];
    }

    public function onTomatoBuy(\Rector\NetteKdyby\Tests\Rector\ClassMethod\ReplaceMagicEventPropertySubscriberWithEventClassSubscriberRector\Fixture\Event\FixtureTomatoBuyEvent $vegetableMarketTomatoBuyEvent): void
    {
        $anotherTomato = $vegetableMarketTomatoBuyEvent->getTomato();
        $anotherTomato->unwrap();
    }
}

?>
