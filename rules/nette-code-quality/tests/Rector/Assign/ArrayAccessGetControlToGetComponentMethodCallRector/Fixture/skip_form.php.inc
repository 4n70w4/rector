<?php

namespace Rector\NetteCodeQuality\Tests\Rector\Assign\ArrayAccessGetControlToGetComponentMethodCallRector\Fixture;

use Nette\Forms\Form;

class SkipForm
{
    public function some()
    {
        $someControl = $this['whatever'];
    }
}
