# priority_queue：优先队列（堆）

头文件：`#include <queue>`。保存 `pair` 时还需 `#include <utility>`。每次要快速取最大值或最小值时使用。

## 默认是大根堆

```cpp
priority_queue<int> pq;
pq.push(3);
pq.push(8);
pq.push(5);

int largest = pq.top();         // 8
pq.pop();                       // 删除 8；pop() 不返回值
```

## 小根堆

还需 `#include <vector>` 和 `#include <functional>`：

```cpp
priority_queue<int, vector<int>, greater<int>> pq;
pq.push(3);
pq.push(8);
pq.push(5);

int smallest = pq.top();        // 3
```

## 保存两个值

```cpp
priority_queue<pair<int, int>> pq;
pq.push({5, 100});              // {优先级, 编号}
pq.push({3, 200});

int priority = pq.top().first;  // 5
int id = pq.top().second;       // 100
```

`pair` 默认先比较 `.first`，相等时再比较 `.second`。把“需要排序的值”放到 `.first` 比较直观。

常用函数：`push(x)` 插入、`top()` 查看堆顶、`pop()` 删除堆顶、`size()` 查看数量、`empty()` 判断是否为空。插入和删除是 `O(log n)`，查看堆顶是 `O(1)`；不能像 `vector` 一样按下标访问或直接遍历。
