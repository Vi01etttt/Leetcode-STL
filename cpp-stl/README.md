# C++ 算法题常用容器速查

示例使用 C++17。代码中默认已经写了 `using namespace std;`；实际提交时还需要引入页面顶部注明的头文件。

| 需求 | 常用容器 | 入口 |
| --- | --- | --- |
| 按下标访问、动态扩容 | `vector` | [vector](./vector.md) |
| 数字到次数、值到下标 | `unordered_map` | [unordered_map](./unordered-map.md) |
| 判断元素是否出现、去重 | `unordered_set` | [unordered_set](./unordered-set.md) |
| 维护有序的键或元素 | `map` / `set` | [map 与 set](./ordered-containers.md) |
| 后进先出、先进先出、两端操作 | `stack` / `queue` / `deque` | [栈、队列与双端队列](./stack-queue-deque.md) |
| 随时取最大或最小元素 | `priority_queue` | [优先队列](./priority-queue.md) |
| 处理子串、字符和搜索 | `string` | [string](./string.md) |
| 同时保存两个值 | `pair` | [pair](./pair.md) |
| 排序、二分、求和等操作 | `<algorithm>` / `<numeric>` | [常用算法函数](./algorithms.md) |

## 看代码时先认清四件事

1. `container.size()` 是元素数量；`container.empty()` 判断是否为空。
2. `pop_back()`、`pop()` 都只负责删除，不返回被删除的元素；要先读取，再删除。
3. `map` / `set` 自动有序，`unordered_map` / `unordered_set` 不保证遍历顺序。
4. `sort`、`reverse`、`find` 等通常是 `<algorithm>` 中的算法，不是 `vector` 的成员函数。

这里列出刷题最常用的写法。更完整的说明见原有笔记：[vector 常用函数](../topics/cpp-vector-functions.md)、[哈希常用函数](../topics/cpp-hash-functions.md)。
