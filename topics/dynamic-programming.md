# 动态规划

## 题型信号

- 最值、计数、可行性。
- 问题可以拆成重复子问题。
- 当前状态依赖之前状态。
- 当前行、当前位置依赖上一行或前几个位置。

## 思考顺序

1. 定义状态。
2. 写出转移方程。
3. 明确初始化。
4. 确定遍历顺序。
5. 返回答案。

## 杨辉三角

当前行依赖上一行：

```cpp
vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;

    for (int i = 0; i < numRows; i++) {
        vector<int> row(i + 1, 1);

        for (int j = 1; j < i; j++) {
            row[j] = ans[i - 1][j - 1] + ans[i - 1][j];
        }

        ans.push_back(row);
    }

    return ans;
}
```

记忆：

```text
两边都是 1
中间 = 上一行左上 + 上一行右上
```

## 高频题

| 题号 | 题目 | 备注 |
| --- | --- | --- |
| 0118 | Pascal's Triangle | 当前行依赖上一行 |
| 0070 | Climbing Stairs | 入门 DP |
| 0198 | House Robber | 线性 DP |
| 0300 | Longest Increasing Subsequence | 子序列 |
| 0322 | Coin Change | 背包 |

