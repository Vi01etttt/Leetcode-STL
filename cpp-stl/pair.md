# pair：保存两个值

头文件：`#include <utility>`。经常保存 `{值, 下标}`、`{距离, 节点}`、`{行, 列}`。

```cpp
pair<int, int> cell = {2, 3};
int row = cell.first;            // 2
int col = cell.second;           // 3

cell.first = 4;                  // 修改第一个值
```

也可以放进 `vector` 或 `queue`；使用时再包含 `<vector>` 或 `<queue>`：

```cpp
vector<pair<int, int>> edges;
edges.push_back({1, 5});

queue<pair<int, int>> q;
q.push({0, 0});
```

C++17 支持结构化绑定：

```cpp
auto [r, c] = cell;              // 拿到两个值的副本
auto& [refR, refC] = cell;       // 引用，可修改 cell
```

`pair` 支持比较：先比较 `.first`，只有第一个值相同时才比较 `.second`。这也是 `vector<pair<int,int>>` 默认排序时的规则。
