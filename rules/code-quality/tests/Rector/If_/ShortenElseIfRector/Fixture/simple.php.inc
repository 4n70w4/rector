<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SimpleClass
{
    /**
     * @var bool
     */
    private $cond1;

    /**
     * @var bool
     */
    private $cond2;

    public function run()
    {
        if ($this->cond1) {
            $this->doSomething();
        } else {
            if ($this->cond2) {
                $this->doSomething();
            }
        }
    }

    public function doSomething()
    {

    }
}

?>
-----
<?php

namespace Rector\TypeDeclaration\Tests\Rector\Property\PropertyTypeDeclarationRector\Fixture;

class SimpleClass
{
    /**
     * @var bool
     */
    private $cond1;

    /**
     * @var bool
     */
    private $cond2;

    public function run()
    {
        if ($this->cond1) {
            $this->doSomething();
        } elseif ($this->cond2) {
            $this->doSomething();
        }
    }

    public function doSomething()
    {

    }
}

?>
