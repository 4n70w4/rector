<?php

namespace Rector\Php71\Tests\Rector\Name\ReservedobjectRector\Fixture;

class Reservedobject
{

}

class ChildObject extends Reservedobject
{

}

$some = new ChildObject();
if ($some instanceof Reservedobject) {
    return;
}

is_subclass_of($some, Reservedobject::class);

is_a($some, Reservedobject::class);

function someFunction(Reservedobject $reservedObject): Reservedobject {
    return $reservedObject;
}

$someObject = new Reservedobject;

?>
-----
<?php

namespace Rector\Php71\Tests\Rector\Name\ReservedobjectRector\Fixture;

class SmartObject
{

}

class ChildObject extends \Rector\Php71\Tests\Rector\Name\ReservedobjectRector\Fixture\SmartObject
{

}

$some = new ChildObject();
if ($some instanceof \Rector\Php71\Tests\Rector\Name\ReservedobjectRector\Fixture\SmartObject) {
    return;
}

is_subclass_of($some, \Rector\Php71\Tests\Rector\Name\ReservedobjectRector\Fixture\SmartObject::class);

is_a($some, \Rector\Php71\Tests\Rector\Name\ReservedobjectRector\Fixture\SmartObject::class);

function someFunction(\Rector\Php71\Tests\Rector\Name\ReservedobjectRector\Fixture\SmartObject $reservedObject): \Rector\Php71\Tests\Rector\Name\ReservedobjectRector\Fixture\SmartObject {
    return $reservedObject;
}

$someObject = new \Rector\Php71\Tests\Rector\Name\ReservedobjectRector\Fixture\SmartObject;

?>
