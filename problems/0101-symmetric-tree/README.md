# 0101. Symmetric Tree

难度：Easy  
专题：Tree, DFS  
链接：https://leetcode.com/problems/symmetric-tree/

## 题意

给定一棵二叉树的根节点 `root`，判断它是否轴对称。

轴对称的意思是：左子树和右子树互为镜像。

## 递归思路

判断两棵树 `left` 和 `right` 是否镜像：

1. 如果两个节点都为空，说明这一部分对称，返回 `true`。
2. 如果只有一个为空，说明结构不对称，返回 `false`。
3. 如果两个节点值不同，返回 `false`。
4. 继续比较外侧和内侧：
   - `left->left` 对 `right->right`
   - `left->right` 对 `right->left`

代码：[solution.cpp](./solution.cpp)

## 复杂度

- 时间复杂度：`O(n)`，每个节点最多访问一次。
- 空间复杂度：`O(h)`，其中 `h` 是树高，来自递归调用栈。

## 易错点

- 不是比较 `left->left` 和 `right->left`，而是镜像比较。
- 两个空节点返回 `true`。
- 一个空一个不空返回 `false`。
- 当前值相等以后，还要继续比较外侧和内侧。

