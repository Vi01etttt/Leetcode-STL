# unordered_map：哈希表

头文件：`#include <unordered_map>`；以下示例还使用 `#include <vector>`。保存 `key -> value`，常用于统计频率、记录下标。

```cpp
unordered_map<int, int> freq;
vector<int> nums = {2, 3, 2};

for (int x : nums) {
    freq[x]++;                    // freq[2] == 2，freq[3] == 1
}
```

| 用法 | 含义 |
| --- | --- |
| `freq[key] = value` | 插入或更新键值对 |
| `freq[key]++` | 计数；新键的 `int` 值从 0 开始 |
| `freq.count(key)` | 键是否存在，返回 0 或 1 |
| `freq.find(key)` | 找到则返回迭代器，否则返回 `freq.end()` |
| `freq.at(key)` | 读取已有键的值；键不存在会抛异常 |
| `freq.erase(key)` | 按键删除，返回删除的元素数，0 或 1 |
| `freq.size()` / `freq.empty()` | 键的数量 / 是否为空 |
| `freq.clear()` | 清空 |

只查询、不想插入新键时，用 `find`：

```cpp
auto it = freq.find(5);
if (it != freq.end()) {
    int count = it->second;
}
```

遍历键值对：

```cpp
for (const auto& [key, count] : freq) {
    // key 是键，count 是出现次数；结构化绑定需要 C++17
}
```

注意：`freq[key]` 在键不存在时会**插入新键**。哈希表不保证遍历顺序；查找、插入和删除平均 `O(1)`，极端碰撞时可退化到 `O(n)`。完整模板见 [哈希函数笔记](../topics/cpp-hash-functions.md)。
