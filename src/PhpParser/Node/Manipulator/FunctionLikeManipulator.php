<?php declare(strict_types=1);

namespace Rector\PhpParser\Node\Manipulator;

use PhpParser\Node\FunctionLike;
use PhpParser\Node\Stmt\ClassMethod;
use PhpParser\Node\Stmt\Function_;
use PhpParser\Node\Stmt\Interface_;
use PhpParser\Node\Stmt\Return_;
use Rector\NodeTypeResolver\Node\Attribute;
use Rector\NodeTypeResolver\NodeTypeResolver;
use Rector\NodeTypeResolver\Php\ReturnTypeInfo;
use Rector\Php\TypeAnalyzer;
use Rector\PhpParser\Node\BetterNodeFinder;

final class FunctionLikeManipulator
{
    /**
     * @var BetterNodeFinder
     */
    private $betterNodeFinder;

    /**
     * @var TypeAnalyzer
     */
    private $typeAnalyzer;

    /**
     * @var NodeTypeResolver
     */
    private $nodeTypeResolver;

    public function __construct(
        BetterNodeFinder $betterNodeFinder,
        TypeAnalyzer $typeAnalyzer,
        NodeTypeResolver $nodeTypeResolver
    ) {
        $this->betterNodeFinder = $betterNodeFinder;
        $this->typeAnalyzer = $typeAnalyzer;
        $this->nodeTypeResolver = $nodeTypeResolver;
    }

    /**
     * Based on static analysis of code, looking for return types
     * @param ClassMethod|Function_ $functionLike
     */
    public function resolveStaticReturnTypeInfo(FunctionLike $functionLike): ?ReturnTypeInfo
    {
        if ($this->shouldSkip($functionLike)) {
            return null;
        }

        /** @var Return_[] $returnNodes */
        $returnNodes = $this->betterNodeFinder->findInstanceOf((array) $functionLike->stmts, Return_::class);

        $isVoid = true;

        $types = [];
        foreach ($returnNodes as $returnNode) {
            if ($returnNode->expr === null) {
                continue;
            }

            $types = array_merge($types, $this->nodeTypeResolver->resolveSingleTypeToStrings($returnNode->expr));
            $isVoid = false;
        }

        if ($isVoid) {
            return new ReturnTypeInfo(['void'], $this->typeAnalyzer);
        }

        $types = array_filter($types);

        return new ReturnTypeInfo($types, $this->typeAnalyzer);
    }

    private function shouldSkip(FunctionLike $functionLike): bool
    {
        if (! $functionLike instanceof ClassMethod) {
            return false;
        }

        $classNode = $functionLike->getAttribute(Attribute::CLASS_NODE);
        // only class or trait method body can be analyzed for returns
        if ($classNode instanceof Interface_) {
            return true;
        }

        // only methods that are not abstract can be analyzed for returns
        return $functionLike->isAbstract();
    }
}
