# 复盘记录

## 识别信号

题目中的操作只包含按位或与按位与，因此可以把每个二进制位拆开独立分析。

恒等关系：

```text
(a or x) + (a and x) = a + x
```

从单个二进制位看，操作保持数组与 `x` 中 `1` 的总数量不变。

## 最终公式

```cpp
int minX = (~allAnd) & validMask;
long long maxSum = originalSum + minX;
```
