# 0145. Binary Tree Postorder Traversal

难度：Easy  
专题：Tree, DFS  
链接：https://leetcode.com/problems/binary-tree-postorder-traversal/

## 题意

给定一棵二叉树，返回它的后序遍历结果。

后序遍历顺序：

```text
左 -> 右 -> 根
```

## 递归思路

递归函数负责遍历当前节点 `node`：

1. 如果 `node == nullptr`，直接返回。
2. 先遍历左子树。
3. 再遍历右子树。
4. 最后记录当前节点值。

代码：[solution.cpp](./solution.cpp)

## 复杂度

- 时间复杂度：`O(n)`
- 空间复杂度：`O(h)`，其中 `h` 是树高，来自递归调用栈。

