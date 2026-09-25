# 0118. Pascal's Triangle

难度：Easy  
专题：Array, Dynamic Programming  
链接：https://leetcode.com/problems/pascals-triangle/

## 题意

给定非负整数 `numRows`，生成杨辉三角的前 `numRows` 行。

杨辉三角中：

- 每一行第一个数和最后一个数都是 `1`。
- 中间每个数等于上一行相邻两个数之和。

## 思路

一行一行构造。

对于第 `i` 行：

- 它有 `i + 1` 个元素。
- 先全部初始化为 `1`。
- 中间位置 `j` 用上一行计算：

```text
row[j] = ans[i - 1][j - 1] + ans[i - 1][j]
```

代码：[solution.cpp](./solution.cpp)

## 复杂度

- 时间复杂度：`O(numRows^2)`
- 空间复杂度：`O(1)` 额外空间，不算返回结果本身。

## 易错点

- 第 `i` 行长度是 `i + 1`。
- 中间位置从 `j = 1` 到 `j < i`。
- 两边的 `1` 不需要额外计算。

