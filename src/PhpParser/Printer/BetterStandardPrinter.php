<?php declare(strict_types=1);

namespace Rector\PhpParser\Printer;

use Nette\Utils\Strings;
use PhpParser\Node;
use PhpParser\Node\Expr\Array_;
use PhpParser\Node\Expr\Closure;
use PhpParser\Node\Expr\Yield_;
use PhpParser\Node\Scalar\DNumber;
use PhpParser\Node\Scalar\EncapsedStringPart;
use PhpParser\Node\Scalar\String_;
use PhpParser\Node\Stmt\Class_;
use PhpParser\Node\Stmt\ClassMethod;
use PhpParser\Node\Stmt\Expression;
use PhpParser\Node\Stmt\Nop;
use PhpParser\Node\Stmt\TraitUse;
use PhpParser\PrettyPrinter\Standard;
use Rector\NodeTypeResolver\Node\AttributeKey;

final class BetterStandardPrinter extends Standard
{
    /**
     * @param mixed[] $options
     */
    public function __construct(array $options = [])
    {
        parent::__construct($options);

        // print return type double colon right after the bracket "function(): string"
        $this->initializeInsertionMap();
        $this->insertionMap['Stmt_ClassMethod->returnType'] = [')', false, ': ', null];
        $this->insertionMap['Stmt_Function->returnType'] = [')', false, ': ', null];
        $this->insertionMap['Expr_Closure->returnType'] = [')', false, ': ', null];
    }

    /**
     * @param Node|Node[]|null $node
     */
    public function print($node): string
    {
        if ($node === null) {
            $node = [];
        }

        if ($node instanceof EncapsedStringPart) {
            return 'UNABLE_TO_PRINT_ENCAPSED_STRING';
        }

        // remove comments, for value compare
        if ($node instanceof Node) {
            $node = clone $node;
            $node->setAttribute('comments', null);
        }

        if (! is_array($node)) {
            $node = [$node];
        }

        return $this->prettyPrint($node);
    }

    /**
     * @param Node|Node[]|null $firstNode
     * @param Node|Node[]|null $secondNode
     */
    public function areNodesEqual($firstNode, $secondNode): bool
    {
        return $this->print($firstNode) === $this->print($secondNode);
    }

    /**
     * @param mixed[] $nodes
     * @param mixed[] $origNodes
     * @param int|null $fixup
     */
    public function pArray(
        array $nodes,
        array $origNodes,
        int &$pos,
        int $indentAdjustment,
        string $parentNodeType,
        string $subNodeName,
        $fixup
    ): ?string {
        // reindex positions for printer
        $nodes = array_values($nodes);

        $content = parent::pArray($nodes, $origNodes, $pos, $indentAdjustment, $parentNodeType, $subNodeName, $fixup);

        if ($content === null) {
            return $content;
        }

        if (! $this->containsNop($nodes)) {
            return $content;
        }

        // remove extra spaces before new Nop_ nodes, @see https://regex101.com/r/iSvroO/1
        return Strings::replace($content, '#^[ \t]+$#m');
        return Strings::replace($content, '#^[ \t]+$#m');
    }

    /**
     * Do not preslash all slashes (parent behavior), but only those:
     *
     * - followed by "\"
     * - by "'"
     * - or the end of the string
     *
     * Prevents `Vendor\Class` => `Vendor\\Class`.
     */
    protected function pSingleQuotedString(string $string): string
    {
        return "'" . Strings::replace($string, "#'|\\\\(?=[\\\\']|$)#", '\\\\$0') . "'";
    }

    /**
     * Emulates 1_000 in PHP 7.3- version
     */
    protected function pScalar_DNumber(DNumber $DNumber): string
    {
        if (is_string($DNumber->value)) {
            return $DNumber->value;
        }

        return parent::pScalar_DNumber($DNumber);
    }

    /**
     * Add space after "use ("
     */
    protected function pExpr_Closure(Closure $closure): string
    {
        return Strings::replace(parent::pExpr_Closure($closure), '#( use)\(#', '$1 (');
    }

    /**
     * Do not add "()" on Expressions
     * @see https://github.com/rectorphp/rector/pull/401#discussion_r181487199
     */
    protected function pExpr_Yield(Yield_ $node): string
    {
        if ($node->value === null) {
            return 'yield';
        }

        $parentNode = $node->getAttribute(AttributeKey::PARENT_NODE);
        $shouldAddBrackets = $parentNode instanceof Expression;

        return sprintf(
            '%syield %s%s%s',
            $shouldAddBrackets ? '(' : '',
            $node->key !== null ? $this->p($node->key) . ' => ' : '',
            $this->p($node->value),
            $shouldAddBrackets ? ')' : ''
        );
    }

    /**
     * Print arrays in short [] by default,
     * to prevent manual explicit array shortening.
     */
    protected function pExpr_Array(Array_ $node): string
    {
        if (! $node->hasAttribute('kind')) {
            $node->setAttribute('kind', Array_::KIND_SHORT);
        }

        return parent::pExpr_Array($node);
    }

    /**
     * Fixes escaping of regular patterns
     */
    protected function pScalar_String(String_ $node): string
    {
        $kind = $node->getAttribute('kind', String_::KIND_SINGLE_QUOTED);
        if ($kind === String_::KIND_DOUBLE_QUOTED && $node->getAttribute('is_regular_pattern')) {
            return '"' . $node->value . '"';
        }

        return parent::pScalar_String($node);
    }

    /**
     * "...$params) : ReturnType"
     * ↓
     * "...$params): ReturnType"
     */
    protected function pStmt_ClassMethod(ClassMethod $classMethod): string
    {
        return $this->pModifiers($classMethod->flags)
            . 'function ' . ($classMethod->byRef ? '&' : '') . $classMethod->name
            . '(' . $this->pCommaSeparated($classMethod->params) . ')'
            . ($classMethod->returnType !== null ? ': ' . $this->p($classMethod->returnType) : '')
            . ($classMethod->stmts !== null ? $this->nl . '{' . $this->pStmts(
                $classMethod->stmts
            ) . $this->nl . '}' : ';');
    }

    /**
     * Clean class and trait from empty "use x;" for traits causing invalid code
     */
    protected function pStmt_Class(Class_ $class): string
    {
        $shouldReindex = false;

        foreach ($class->stmts as $key => $stmt) {
            if ($stmt instanceof TraitUse) {
                // remove empty ones
                if (count($stmt->traits) === 0) {
                    unset($class->stmts[$key]);
                    $shouldReindex = true;
                }
            }
        }

        if ($shouldReindex) {
            $class->stmts = array_values($class->stmts);
        }

        return parent::pStmt_Class($class);
    }

    /**
     * @param Node[] $nodes
     */
    private function containsNop(array $nodes): bool
    {
        foreach ($nodes as $node) {
            if ($node instanceof Nop) {
                return true;
            }
        }

        return false;
    }
}
