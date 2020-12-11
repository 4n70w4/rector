<?php

namespace Rector\CodingStyle\Tests\Rector\Throw_\AnnotateThrowablesRector\Fixture;

use Rector\CodingStyle\Tests\Rector\Throw_\UseOfAMethodOfAClassPassedAsParameternnotateThrowablesRector\Source\Exceptions\TheException;

class UseOfAMethodOfAClassPassedAsParameter
{
    /**
     * @throws TheException
     */
    public function thisMethodThrowsUseOfAMethodOfAClassPassedAsParameternException():string
    {
        throw new TheException('');
    }
}

class UseUseOfAMethodOfAClassPassedAsParameterClassWithUseOfAMethodOfAClassPassedAsParameterMethodThatMayThrowUseOfAMethodOfAClassPassedAsParameternException
{
    /**
     * @param UseOfAMethodOfAClassPassedAsParameter $theClass
     */
    public function thisMethodUsesTheClassWithTheMethodThatTrhowsUseOfAMethodOfAClassPassedAsParameternException(UseOfAMethodOfAClassPassedAsParameter $theClass)
    {
        $aVariable = $theClass->thisMethodThrowsUseOfAMethodOfAClassPassedAsParameternException();
    }
}

?>
-----
<?php

namespace Rector\CodingStyle\Tests\Rector\Throw_\AnnotateThrowablesRector\Fixture;

use Rector\CodingStyle\Tests\Rector\Throw_\UseOfAMethodOfAClassPassedAsParameternnotateThrowablesRector\Source\Exceptions\TheException;

class UseOfAMethodOfAClassPassedAsParameter
{
    /**
     * @throws TheException
     */
    public function thisMethodThrowsUseOfAMethodOfAClassPassedAsParameternException():string
    {
        throw new TheException('');
    }
}

class UseUseOfAMethodOfAClassPassedAsParameterClassWithUseOfAMethodOfAClassPassedAsParameterMethodThatMayThrowUseOfAMethodOfAClassPassedAsParameternException
{
    /**
     * @param UseOfAMethodOfAClassPassedAsParameter $theClass
     * @throws \Rector\CodingStyle\Tests\Rector\Throw_\UseOfAMethodOfAClassPassedAsParameternnotateThrowablesRector\Source\Exceptions\TheException
     */
    public function thisMethodUsesTheClassWithTheMethodThatTrhowsUseOfAMethodOfAClassPassedAsParameternException(UseOfAMethodOfAClassPassedAsParameter $theClass)
    {
        $aVariable = $theClass->thisMethodThrowsUseOfAMethodOfAClassPassedAsParameternException();
    }
}

?>
