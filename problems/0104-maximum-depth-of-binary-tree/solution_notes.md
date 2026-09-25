# 0104. Maximum Depth of Binary Tree 复盘

## 核心递归

```cpp
if (root == nullptr) return 0;

return max(maxDepth(root->left), maxDepth(root->right)) + 1;
```

## 识别信号

- 问二叉树最大深度。
- 要从根节点走到最远叶子节点。
- 左右子树都要看，然后取最大值。

这种题一般是后序思想：先知道左右子树答案，再合成当前节点答案。

## 下次重写检查

- 空节点是否返回 `0`？
- 当前节点这一层是否 `+ 1`？
- 是否用了左右子树的最大值？

