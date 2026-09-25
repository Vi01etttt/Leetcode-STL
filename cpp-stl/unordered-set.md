# unordered_set：哈希集合

头文件：`#include <unordered_set>`。只保存不重复的值，常用于判断“出现过吗”。

```cpp
unordered_set<int> seen;

seen.insert(3);                  // 插入 3
seen.insert(3);                  // 重复插入后仍只有一个 3

if (seen.count(3)) {
    // 3 已经出现过
}

seen.erase(3);                   // 删除 3
```

| 用法 | 含义 |
| --- | --- |
| `seen.insert(x)` | 插入 x；返回的 `pair` 中 `.second` 表示是否插入成功 |
| `seen.count(x)` | 存在返回 1，否则返回 0 |
| `seen.find(x)` | 存在返回迭代器，否则返回 `seen.end()` |
| `seen.erase(x)` | 删除 x，返回删除的元素数 |
| `seen.size()` / `seen.empty()` | 元素数 / 是否为空 |
| `seen.clear()` | 清空集合 |

去重判断模板：

```cpp
unordered_set<int> seen;
for (int x : nums) {
    if (seen.count(x)) {
        return true;             // 发现重复
    }
    seen.insert(x);
}
return false;
```

集合中的元素没有下标，也不保证遍历顺序。查找、插入和删除平均 `O(1)`，极端碰撞时可退化到 `O(n)`。需要自动排序时使用 `set`。
