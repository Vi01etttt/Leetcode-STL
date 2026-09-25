# 0104. Maximum Depth of Binary Tree

难度：Easy  
专题：Tree, DFS  
链接：https://leetcode.com/problems/maximum-depth-of-binary-tree/

## 题意

给定一棵二叉树，返回它的最大深度。

最大深度是从根节点到最远叶子节点路径上的节点数量。

## 递归思路

空树没有节点，所以深度是 `0`。

如果当前节点不是空：

```text
当前树最大深度 = max(左子树最大深度, 右子树最大深度) + 1
```

这里的 `+ 1` 表示当前节点自己这一层。

代码：[solution.cpp](./solution.cpp)

## 复杂度

- 时间复杂度：`O(n)`，每个节点访问一次。
- 空间复杂度：`O(h)`，其中 `h` 是树高，来自递归调用栈。

## 易错点

- `root == nullptr` 时返回 `0`。
- 最后要 `+ 1`，因为当前节点也算一层。
- 不是求节点值最大，而是求路径层数最大。

