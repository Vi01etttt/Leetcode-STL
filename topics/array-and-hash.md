# 数组与哈希表

## 题型信号

- 需要快速判断一个元素是否出现过。
- 需要统计频次。
- 需要保存值到下标、值到次数、值到状态的映射。
- 题目中出现“两数之和”“是否重复”“分组”“计数”等关键词。

## C++ 常用容器

- `unordered_map<Key, Value>`：哈希表，保存 `key -> value`。
- `unordered_set<T>`：哈希集合，只关心元素是否出现过。
- `map<Key, Value>`：有序映射，底层红黑树，按 key 排序。
- `set<T>`：有序集合，底层红黑树，按值排序。

刷题里如果不需要顺序，优先用 `unordered_map` / `unordered_set`。

更多函数速查见：[C++ 哈希常用函数](./cpp-hash-functions.md)

## 常见套路

### 查补数

用于 Two Sum 这类题。

```cpp
unordered_map<int, int> seen;

for (int i = 0; i < nums.size(); i++) {
    int need = target - nums[i];

    if (seen.count(need)) {
        return {seen[need], i};
    }

    seen[nums[i]] = i;
}
```

### 频次统计

```cpp
unordered_map<int, int> count;

for (int x : nums) {
    count[x]++;
}
```

### 判断是否出现过

```cpp
unordered_set<int> seen;

for (int x : nums) {
    if (seen.count(x)) {
        return true;
    }
    seen.insert(x);
}

return false;
```

### 按频率分桶

当频率范围是 `[1, n]` 时，可以把频率直接作为数组下标，避免排序：

```cpp
unordered_map<int, int> frequency;

for (int num : nums) {
    frequency[num]++;
}

vector<vector<int>> buckets(nums.size() + 1);

for (const auto& entry : frequency) {
    int num = entry.first;
    int count = entry.second;
    buckets[count].push_back(num);
}
```

`buckets[3]` 中保存的，就是所有恰好出现三次的数字。

## 高频题

| 题号 | 题目 | 备注 |
| --- | --- | --- |
| 0001 | Two Sum | 查补数 |
| 0217 | Contains Duplicate | 集合去重 |
| 0242 | Valid Anagram | 频次统计 |
| 0049 | Group Anagrams | 归一化 key |
| 0347 | Top K Frequent Elements | 频次统计 + 桶排序 |
