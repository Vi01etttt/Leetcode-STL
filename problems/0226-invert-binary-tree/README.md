# 0226. Invert Binary Tree

难度：Easy  
专题：Tree, DFS  
链接：https://leetcode.com/problems/invert-binary-tree/

## 题意

给定一棵二叉树的根节点 `root`，翻转这棵二叉树，并返回根节点。

翻转的意思是：每个节点的左孩子和右孩子都交换。

## 递归思路

对于每个节点：

1. 如果当前节点是空，直接返回 `nullptr`。
2. 交换当前节点的左孩子和右孩子。
3. 递归翻转左子树。
4. 递归翻转右子树。
5. 返回当前节点。

代码：[solution.cpp](./solution.cpp)

## 复杂度

- 时间复杂度：`O(n)`，每个节点访问一次。
- 空间复杂度：`O(h)`，其中 `h` 是树高，来自递归调用栈。

## 易错点

- 空节点要直接返回。
- 交换的是指针：`root->left` 和 `root->right`。
- 返回值还是原来的根节点 `root`，只是它下面的左右子树已经被翻转。

