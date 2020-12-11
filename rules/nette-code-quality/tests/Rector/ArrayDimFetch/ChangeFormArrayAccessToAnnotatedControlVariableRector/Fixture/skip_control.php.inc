<?php

namespace Rector\NetteCodeQuality\Tests\Rector\ArrayDimFetch\ChangeFormArrayAccessToAnnotatedControlVariableRector\Fixture;

use Nette\Application\UI\Control;
use Nette\Application\UI\Form;

class SkipControl
{
    public function run()
    {
        $this['some_form']->values();
    }

    public function createComponentSomeForm(): Form
    {
        return new Form();
    }
}
