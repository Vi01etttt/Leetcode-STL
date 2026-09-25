# 0101. Symmetric Tree 复盘

## 核心递归

```cpp
bool isMirror(TreeNode* left, TreeNode* right) {
    if (left == nullptr && right == nullptr) return true;
    if (left == nullptr || right == nullptr) return false;
    if (left->val != right->val) return false;

    return isMirror(left->left, right->right) &&
           isMirror(left->right, right->left);
}
```

## 识别信号

- 判断二叉树是否对称。
- 要比较左子树和右子树。
- 比较方向是镜像方向。

## 下次重写检查

- 两个空节点是否返回 `true`？
- 一个空一个不空是否返回 `false`？
- 是否比较了节点值？
- 是否比较了外侧：`left->left` 和 `right->right`？
- 是否比较了内侧：`left->right` 和 `right->left`？

