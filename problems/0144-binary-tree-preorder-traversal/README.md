# 0144. Binary Tree Preorder Traversal

难度：Easy  
专题：Tree, DFS  
链接：https://leetcode.com/problems/binary-tree-preorder-traversal/

## 题意

给定一棵二叉树，返回它的先序遍历结果。

先序遍历顺序：

```text
根 -> 左 -> 右
```

## 递归思路

递归函数负责遍历当前节点 `node`：

1. 如果 `node == nullptr`，直接返回。
2. 先记录当前节点值。
3. 再遍历左子树。
4. 最后遍历右子树。

代码：[solution.cpp](./solution.cpp)

## 复杂度

- 时间复杂度：`O(n)`
- 空间复杂度：`O(h)`，其中 `h` 是树高，来自递归调用栈。

