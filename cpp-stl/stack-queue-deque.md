# 栈、队列与双端队列

## stack：后进先出

头文件：`#include <stack>`。括号匹配、单调栈、撤销操作常用。

```cpp
stack<int> st;
st.push(1);
st.push(2);
int last = st.top();             // 2
st.pop();                       // 删除 2，pop() 不返回值
bool isEmpty = st.empty();
auto count = st.size();
```

只能通过 `top()` 读取栈顶；`stack` 没有 `operator[]` 或可直接遍历的 `begin()`。

## queue：先进先出

头文件：`#include <queue>`。广度优先搜索（BFS）常用。

```cpp
queue<int> q;
q.push(10);
q.push(20);
int first = q.front();          // 10
int last = q.back();            // 20
q.pop();                        // 删除队头 10
```

处理 BFS 中的一层：

```cpp
int levelSize = static_cast<int>(q.size());
for (int i = 0; i < levelSize; i++) {
    int cur = q.front();
    q.pop();
    // 处理 cur，并可在这里加入下一层节点
}
```

## deque：两端都能操作

头文件：`#include <deque>`。单调队列、从两端增删时常用。

```cpp
deque<int> dq;
dq.push_back(2);                // [2]
dq.push_front(1);               // [1, 2]
int left = dq.front();          // 1
int right = dq.back();          // 2
dq.pop_front();                 // [2]
dq.pop_back();                  // []
```

这三种容器都有 `empty()` 和 `size()`。在 `top()`、`front()`、`back()` 或 `pop()` 之前先确认非空。`stack` / `queue` 的 `push`、`pop` 和读取端点通常是 `O(1)`；`deque` 两端增删也是 `O(1)`。
