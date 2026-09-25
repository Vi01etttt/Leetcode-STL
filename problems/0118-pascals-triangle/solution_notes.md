# 0118. Pascal's Triangle 复盘

## 核心代码

```cpp
for (int i = 0; i < numRows; i++) {
    vector<int> row(i + 1, 1);

    for (int j = 1; j < i; j++) {
        row[j] = ans[i - 1][j - 1] + ans[i - 1][j];
    }

    ans.push_back(row);
}
```

## 识别信号

- 当前行依赖上一行。
- 每个中间数字由上一行两个相邻数字相加得到。
- 要返回所有行。

这种题可以看成简单动态规划，也可以看成二维数组模拟。

## 下次重写检查

- `row` 是否初始化成 `i + 1` 个 `1`？
- 中间循环是否从 `1` 开始？
- 中间循环是否写成 `j < i`？
- 是否把每一行 `push_back` 到答案里？

