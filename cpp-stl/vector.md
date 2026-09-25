# vector：可变长数组

头文件：`#include <vector>`。需要按下标访问、末尾追加元素或创建二维数组时使用。

```cpp
vector<int> a;                    // 空数组
vector<int> b(3, 7);              // [7, 7, 7]
vector<int> c = {1, 2, 3};        // [1, 2, 3]
vector<vector<int>> grid(2, vector<int>(3, 0)); // 2 行 3 列
```

| 用法 | 含义 |
| --- | --- |
| `c.push_back(4)` | 末尾添加 4，平均 `O(1)` |
| `c.emplace_back(4)` | 在末尾构造元素；存 `int` 时和 `push_back` 用法近似 |
| `c.back()` / `c.front()` | 读取最后 / 第一个元素，空数组不能调用 |
| `c.pop_back()` | 删除最后一个元素，`O(1)`，没有返回值 |
| `c[i]` | 按下标读取或修改，`O(1)`，不检查越界 |
| `c.at(i)` | 按下标访问，越界时抛异常 |
| `c.size()` / `c.empty()` | 元素数量 / 是否为空 |
| `c.resize(5, 0)` | 改为 5 个元素，新增元素设为 0 |
| `c.reserve(100)` | 预留容量；**不会**把元素数量变成 100 |
| `c.insert(c.begin() + 1, 9)` | 在下标 1 之前插入 9，通常 `O(n)` |
| `c.erase(c.begin() + 1)` | 删除下标 1 的元素，通常 `O(n)` |
| `c.clear()` | 删除所有元素 |

常见遍历与排序：

```cpp
#include <algorithm>

for (int x : c) { /* x 是副本 */ }
for (int& x : c) { x *= 2; }       // 引用可以修改原元素
sort(c.begin(), c.end());         // 升序；sort 来自 <algorithm>
reverse(c.begin(), c.end());      // 反转
```

`begin()` 指向第一个元素，`end()` 指向末尾之后，不能访问 `*c.end()`。插入、删除元素可能让原有迭代器失效。完整用法见 [vector 函数笔记](../topics/cpp-vector-functions.md)。
