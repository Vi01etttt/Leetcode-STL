# 树

## 题型信号

- 二叉树遍历。
- 递归定义天然适合 DFS。
- 层级问题常用 BFS。
- 每个节点都要处理一次，通常是 `O(n)`。

## 二叉树三种 DFS 遍历

区别只在于“根节点什么时候处理”。

| 遍历 | 顺序 | 记忆 |
| --- | --- | --- |
| 先序 | 根 -> 左 -> 右 | 根在前 |
| 中序 | 左 -> 根 -> 右 | 根在中间 |
| 后序 | 左 -> 右 -> 根 | 根在后 |

### 先序遍历

```cpp
void dfs(TreeNode* node, vector<int>& ans) {
    if (node == nullptr) return;

    ans.push_back(node->val);
    dfs(node->left, ans);
    dfs(node->right, ans);
}
```

### 中序遍历

```cpp
void dfs(TreeNode* node, vector<int>& ans) {
    if (node == nullptr) return;

    dfs(node->left, ans);
    ans.push_back(node->val);
    dfs(node->right, ans);
}
```

### 后序遍历

```cpp
void dfs(TreeNode* node, vector<int>& ans) {
    if (node == nullptr) return;

    dfs(node->left, ans);
    dfs(node->right, ans);
    ans.push_back(node->val);
}
```

## 判断对称二叉树

```cpp
bool isMirror(TreeNode* left, TreeNode* right) {
    if (left == nullptr && right == nullptr) return true;
    if (left == nullptr || right == nullptr) return false;
    if (left->val != right->val) return false;

    return isMirror(left->left, right->right) &&
           isMirror(left->right, right->left);
}
```

记忆：

```text
外侧对外侧，内侧对内侧
left->left  对 right->right
left->right 对 right->left
```

## 求最大深度

```cpp
int maxDepth(TreeNode* root) {
    if (root == nullptr) return 0;

    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    return max(leftDepth, rightDepth) + 1;
}
```

记忆：

```text
空节点深度 = 0
当前节点深度 = 左右子树最大深度 + 1
```

## 翻转二叉树

```cpp
TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) return nullptr;

    swap(root->left, root->right);

    invertTree(root->left);
    invertTree(root->right);

    return root;
}
```

记忆：

```text
每个节点都交换左右孩子
```

## 高频题

| 题号 | 题目 | 备注 |
| --- | --- | --- |
| 0094 | Binary Tree Inorder Traversal | 中序 |
| 0101 | Symmetric Tree | 判断镜像 |
| 0104 | Maximum Depth of Binary Tree | DFS |
| 0144 | Binary Tree Preorder Traversal | 先序 |
| 0145 | Binary Tree Postorder Traversal | 后序 |
| 0226 | Invert Binary Tree | 递归交换左右孩子 |
| 0102 | Binary Tree Level Order Traversal | BFS |
| 0236 | Lowest Common Ancestor | 后序思维 |

