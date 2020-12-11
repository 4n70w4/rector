<?php

namespace Rector\Laravel\Tests\Rector\ClassMethod\AddParentBootToModelClassMethodRector\Fixture;

use Illuminate\Database\Eloquent\Model;

class Fixture
{
    public function boot()
    {
    }
}

?>
-----
<?php

namespace Rector\Laravel\Tests\Rector\ClassMethod\AddParentBootToModelClassMethodRector\Fixture;

use Illuminate\Database\Eloquent\Model;

class Fixture
{
    public function boot()
    {
        parent::boot();
    }
}

?>
