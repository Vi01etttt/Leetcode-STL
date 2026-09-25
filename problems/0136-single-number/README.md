# 0136. Single Number

难度：Easy  
专题：Bit Manipulation, Hash Table  
链接：https://leetcode.com/problems/single-number/

## 题意

给定一个非空整数数组 `nums`。

除了某个元素只出现一次以外，其余每个元素都出现两次。返回那个只出现一次的元素。

要求：

- 时间复杂度：`O(n)`
- 额外空间复杂度：`O(1)`

## 解法一：哈希表统计频次

先用哈希表统计每个数字出现的次数，再找出现次数为 `1` 的数字。

代码：[solution_hash.cpp](./solution_hash.cpp)

### 写法

```cpp
unordered_map<int, int> count;

for (int x : nums) {
    count[x]++;
}

for (auto& [num, freq] : count) {
    if (freq == 1) {
        return num;
    }
}
```

### 复杂度

- 时间复杂度：`O(n)`
- 空间复杂度：`O(n)`

### 注意

哈希解法很直观，但不满足题目要求的 `O(1)` 额外空间。

它适合一刷理解题意，但面试和最终提交更推荐异或解法。

## 解法二：异或

异或有三个关键性质：

```text
x ^ x = 0
x ^ 0 = x
异或满足交换律和结合律
```

所以所有数字异或在一起，出现两次的数字都会抵消成 `0`，最后只剩下出现一次的数字。

代码：[solution_xor.cpp](./solution_xor.cpp)

### 例子

```text
[4, 1, 2, 1, 2]

4 ^ 1 ^ 2 ^ 1 ^ 2
= 4 ^ (1 ^ 1) ^ (2 ^ 2)
= 4 ^ 0 ^ 0
= 4
```

### 复杂度

- 时间复杂度：`O(n)`
- 空间复杂度：`O(1)`

## 易错点

- 哈希表统计频次需要 `O(n)` 空间，不满足本题的进阶要求。
- 异或不是按相邻元素抵消，而是因为交换律，所有相同数字最终都能两两抵消。
- 初始化答案可以写成 `int ans = 0;`，因为 `0 ^ x = x`。

