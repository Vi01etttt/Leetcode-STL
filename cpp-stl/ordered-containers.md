# map 与 set：有序容器

头文件：`#include <map>`、`#include <set>`。`map` 保存有序键值对，`set` 保存有序且不重复的元素；默认从小到大遍历。

## map

```cpp
map<int, int> freq;
freq[5]++;
freq[2] = 3;

for (const auto& [key, value] : freq) {
    // key 依次是 2、5（C++17）
}
```

常用函数：`mp[key]`、`mp.count(key)`、`mp.find(key)`、`mp.erase(key)`、`mp.size()`、`mp.empty()`。和 `unordered_map` 一样，`mp[key]` 在键不存在时会插入默认值。

## set

```cpp
set<int> st = {5, 2, 5};        // 实际保存 {2, 5}
st.insert(3);                   // {2, 3, 5}
st.erase(2);                    // {3, 5}

if (st.count(5)) { /* 5 存在 */ }
int smallest = *st.begin();     // 最小值；需要确保非空
int largest = *st.rbegin();     // 最大值；需要确保非空
```

## 找下界和上界

```cpp
auto it = st.lower_bound(4);    // 第一个 >= 4 的元素
auto jt = st.upper_bound(4);    // 第一个 > 4 的元素

if (it != st.end()) {
    int value = *it;
}
```

`map` 也有 `lower_bound(key)` / `upper_bound(key)`；返回迭代器的 `->first` 是键，`->second` 是值。

| 容器 | 内容 | 遍历顺序 | 查找 / 插入 / 删除 |
| --- | --- | --- | --- |
| `map` | 键值对 | 按键升序 | `O(log n)` |
| `set` | 不重复的值 | 升序 | `O(log n)` |
| `unordered_map` | 键值对 | 不保证顺序 | 平均 `O(1)` |
| `unordered_set` | 不重复的值 | 不保证顺序 | 平均 `O(1)` |

注意：`map` / `set` 的迭代器不能像 `vector` 那样写 `begin() + 1`。要允许重复键或重复值时，分别使用 `multimap` 或 `multiset`。
