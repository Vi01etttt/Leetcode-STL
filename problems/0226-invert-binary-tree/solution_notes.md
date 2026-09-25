# 0226. Invert Binary Tree 复盘

## 核心递归

```cpp
if (root == nullptr) return nullptr;

swap(root->left, root->right);

invertTree(root->left);
invertTree(root->right);

return root;
```

## 识别信号

- 翻转二叉树。
- 每个节点都要交换左右孩子。
- 返回根节点。

## 下次重写检查

- 是否处理了空节点？
- 是否交换的是 `root->left` 和 `root->right`？
- 交换后是否继续递归左右子树？
- 最后是否返回 `root`？

