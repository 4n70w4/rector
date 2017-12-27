<?php declare(strict_types=1);

namespace Rector\Rector\Contrib\Nette\Application;

use PhpParser\Node;
use PhpParser\Node\Expr\MethodCall;
use Rector\Node\MethodCallNodeFactory;
use Rector\NodeAnalyzer\MethodCallAnalyzer;
use Rector\NodeChanger\MethodNameChanger;
use Rector\Rector\AbstractRector;

/**
 * Before:
 * - $this->template->registerHelper('someFilter', ...);
 *
 * After:
 * - $this->template->getLatte()->addFilter('someFilter', ...)
 */
final class TemplateRegisterHelperRector extends AbstractRector
{
    /**
     * @var MethodCallAnalyzer
     */
    private $methodCallAnalyzer;

    /**
     * @var MethodNameChanger
     */
    private $methodNameChanger;

    /**
     * @var MethodCallNodeFactory
     */
    private $methodCallNodeFactory;

    public function __construct(MethodCallAnalyzer $methodCallAnalyzer, MethodNameChanger $methodNameChanger, MethodCallNodeFactory $methodCallNodeFactory)
    {
        $this->methodCallAnalyzer = $methodCallAnalyzer;
        $this->methodNameChanger = $methodNameChanger;
        $this->methodCallNodeFactory = $methodCallNodeFactory;
    }

    public function isCandidate(Node $node): bool
    {
        return $this->methodCallAnalyzer->isTypeAndMethod(
            $node,
            'Nette\Bridges\ApplicationLatte\Template',
            'registerHelper'
        );
    }

    /**
     * @param MethodCall $methodCallNode
     */
    public function refactor(Node $methodCallNode): Node
    {
        $this->methodNameChanger->renameNode($methodCallNode, 'addFilter');

        $methodCallNode->var = $this->methodCallNodeFactory->createWithVariableAndMethodName(
            $methodCallNode->var,
            'getLatte'
        );

        return $methodCallNode;
    }
}
