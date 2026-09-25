# 复盘记录

## 识别信号

- 题目要求前 `k` 个高频元素。
- 题目要求时间复杂度优于 `O(n log n)`。
- 元素的频率范围固定在 `[1, n]`，可以把频率作为桶的下标。

## 两步模板

```cpp
unordered_map<int, int> frequency;
for (int num : nums) {
    frequency[num]++;
}

vector<vector<int>> buckets(nums.size() + 1);
for (const auto& entry : frequency) {
    buckets[entry.second].push_back(entry.first);
}
```

然后从 `buckets[n]` 倒序扫描到 `buckets[1]`。
