# 滑动窗口

## 题型信号

- 子数组、子串、连续区间。
- 求最长、最短、最多、最少。
- 窗口内需要满足某个条件。

## 核心问题

滑动窗口的重点是搞清楚：

- 右边界什么时候扩张？
- 左边界什么时候收缩？
- 什么时候更新答案？
- 窗口内维护什么状态？

## 无重复字符窗口模板

使用哈希集合保存当前窗口中的字符：

```cpp
unordered_set<char> window;
int left = 0;
int answer = 0;

for (int right = 0; right < s.size(); right++) {
    while (window.count(s[right])) {
        window.erase(s[left]);
        left++;
    }

    window.insert(s[right]);
    answer = max(answer, right - left + 1);
}
```

这个模板有三个不变量：

- `[left, right]` 是当前连续窗口。
- 集合中恰好保存窗口里的字符。
- `left` 和 `right` 都只向右移动。

## 高频题

| 题号 | 题目 | 备注 |
| --- | --- | --- |
| 0003 | Longest Substring Without Repeating Characters | 去重窗口 |
| 0076 | Minimum Window Substring | 覆盖窗口 |
| 0209 | Minimum Size Subarray Sum | 最短窗口 |
