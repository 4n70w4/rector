<?php

namespace Rector\NetteCodeQuality\Tests\Rector\Assign\ArrayAccessGetControlToGetComponentMethodCallRector\Fixture;

use Nette\Application\UI\Presenter;

class CreateComponent
{
    public function someAction()
    {
        $form = $this['someForm'];
    }

    protected function createComponentSomeForm()
    {
        return new Form();
    }
}

?>
-----
<?php

namespace Rector\NetteCodeQuality\Tests\Rector\Assign\ArrayAccessGetControlToGetComponentMethodCallRector\Fixture;

use Nette\Application\UI\Presenter;

class CreateComponent
{
    public function someAction()
    {
        $form = $this->getComponent('someForm');
    }

    protected function createComponentSomeForm()
    {
        return new Form();
    }
}

?>
