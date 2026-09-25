# C++ vector 常用函数速查

使用 `vector` 需要包含头文件：

```cpp
#include <vector>
using namespace std;
```

`vector` 是长度可以动态变化的数组，支持通过下标快速访问元素。

## 一、创建 vector

```cpp
vector<int> nums;                 // 空数组：[]
vector<int> nums1(5);             // 5 个 0：[0,0,0,0,0]
vector<int> nums2(5, 10);         // 5 个 10：[10,10,10,10,10]
vector<int> nums3 = {1, 2, 3};    // [1,2,3]
```

创建二维 `vector`：

```cpp
int rows = 3;
int cols = 4;

vector<vector<int>> matrix(
    rows,
    vector<int>(cols, 0)
);
```

上面的 `matrix` 是一个 `3 x 4`、所有元素初始为 `0` 的二维数组。

## 二、添加元素

### push_back(value)

在末尾添加一个元素：

```cpp
vector<int> nums;

nums.push_back(10);  // [10]
nums.push_back(20);  // [10,20]
```

时间复杂度：平均 `O(1)`。

### emplace_back(value)

也是在末尾添加元素：

```cpp
nums.emplace_back(30);  // [10,20,30]
```

对于 `int` 来说，它和 `push_back()` 基本没有区别。存放自定义对象时，`emplace_back()` 可以直接调用构造函数。

### insert(position, value)

在指定迭代器位置之前插入元素：

```cpp
vector<int> nums = {1, 3};

nums.insert(nums.begin() + 1, 2);
// [1,2,3]
```

在中间插入后，后面的元素需要移动，时间复杂度为 `O(n)`。

一次插入多个相同元素：

```cpp
nums.insert(nums.begin(), 3, 0);
// 在开头插入 3 个 0
```

## 三、删除元素

### pop_back()

删除最后一个元素：

```cpp
vector<int> nums = {1, 2, 3};

nums.pop_back();  // [1,2]
```

注意：

- `pop_back()` 没有返回值。
- 空数组不能调用 `pop_back()`。
- 时间复杂度为 `O(1)`。

如果需要保存最后一个元素：

```cpp
int last = nums.back();
nums.pop_back();
```

### erase(position)

删除指定位置的元素：

```cpp
vector<int> nums = {10, 20, 30};

nums.erase(nums.begin() + 1);
// [10,30]
```

`erase()` 返回被删除位置后面的迭代器。

### erase(first, last)

删除一段区间，区间是 `[first, last)`，包含 `first`，不包含 `last`：

```cpp
vector<int> nums = {1, 2, 3, 4, 5};

nums.erase(nums.begin() + 1, nums.begin() + 4);
// 删除下标 1、2、3，结果为 [1,5]
```

### clear()

删除所有元素：

```cpp
nums.clear();
```

执行后 `nums.size()` 为 `0`，但已经申请的容量不一定马上释放。

### 删除所有等于 target 的元素

`vector` 没有直接“按值删除”的成员函数。C++17 中常用 `remove + erase`：

```cpp
#include <algorithm>

vector<int> nums = {1, 2, 2, 3};
int target = 2;

nums.erase(
    remove(nums.begin(), nums.end(), target),
    nums.end()
);
// [1,3]
```

## 四、访问元素

### operator[]

通过下标访问：

```cpp
vector<int> nums = {10, 20, 30};

cout << nums[0];  // 10
nums[1] = 99;     // [10,99,30]
```

`[]` 不检查下标是否越界，访问速度快。越界访问会产生未定义行为。

### at(index)

带越界检查的下标访问：

```cpp
cout << nums.at(1);  // 99
```

如果下标越界，`at()` 会抛出异常。

### front()

访问第一个元素：

```cpp
int first = nums.front();
```

### back()

访问最后一个元素：

```cpp
int last = nums.back();
```

空数组不能调用 `front()` 或 `back()`。

## 五、大小和容量

### size()

返回当前元素数量：

```cpp
int n = nums.size();
```

严格来说，`size()` 返回的是无符号类型 `size_t`。在倒序循环中，可以先转换为 `int`：

```cpp
for (int i = static_cast<int>(nums.size()) - 1; i >= 0; i--) {
    cout << nums[i] << ' ';
}
```

### empty()

判断是否为空：

```cpp
if (nums.empty()) {
    cout << "vector is empty";
}
```

优先使用 `nums.empty()`，它比 `nums.size() == 0` 更直接。

### resize(newSize)

改变元素数量：

```cpp
vector<int> nums = {1, 2, 3};

nums.resize(5);      // [1,2,3,0,0]
nums.resize(2);      // [1,2]
nums.resize(4, 9);   // [1,2,9,9]
```

`resize()` 会真正改变 `size()`。

### reserve(newCapacity)

提前申请容量，减少扩容次数：

```cpp
vector<int> nums;

nums.reserve(1000);
```

注意：`reserve(1000)` 只是预留空间，`nums.size()` 仍然是 `0`，不能直接访问 `nums[0]`。

### capacity()

查看当前已经申请的容量：

```cpp
cout << nums.capacity();
```

容量是当前不重新申请内存时最多能容纳的元素数量，可能大于 `size()`。

## 六、修改整个 vector

### assign(count, value)

用指定数量的相同元素替换原内容：

```cpp
vector<int> nums = {1, 2, 3};

nums.assign(4, 7);
// [7,7,7,7]
```

### swap(other)

交换两个 `vector`：

```cpp
vector<int> a = {1, 2};
vector<int> b = {3, 4, 5};

a.swap(b);
// a = [3,4,5]
// b = [1,2]
```

## 七、迭代器

### begin() 和 end()

```cpp
nums.begin();  // 指向第一个元素
nums.end();    // 指向最后一个元素后面的位置
```

注意：`end()` 不指向最后一个元素，不能解引用。

遍历示例：

```cpp
for (auto it = nums.begin(); it != nums.end(); it++) {
    cout << *it << ' ';
}
```

### rbegin() 和 rend()

用于反向遍历：

```cpp
for (auto it = nums.rbegin(); it != nums.rend(); it++) {
    cout << *it << ' ';
}
```

## 八、常见遍历写法

### 只读取元素

```cpp
for (int num : nums) {
    cout << num << ' ';
}
```

这里的 `num` 是元素的副本，修改 `num` 不会改变原数组。

### 修改元素

```cpp
for (int& num : nums) {
    num *= 2;
}
```

`&` 表示引用，修改 `num` 会直接修改 `vector` 中的元素。

### 使用下标

```cpp
for (int i = 0; i < nums.size(); i++) {
    cout << "下标：" << i << "，值：" << nums[i] << '\n';
}
```

## 九、常和 vector 一起使用的算法

这些是 `<algorithm>` 或 `<numeric>` 中的函数，不是 `vector` 自身的成员函数。

### sort()

```cpp
#include <algorithm>

sort(nums.begin(), nums.end());
// 从小到大排序
```

从大到小排序：

```cpp
#include <functional>

sort(nums.begin(), nums.end(), greater<int>());
```

### reverse()

```cpp
reverse(nums.begin(), nums.end());
```

### find()

```cpp
auto it = find(nums.begin(), nums.end(), target);

if (it != nums.end()) {
    cout << "找到了";
}
```

### count()

```cpp
int times = count(nums.begin(), nums.end(), target);
```

### max_element() 和 min_element()

返回迭代器，需要使用 `*` 取得元素值：

```cpp
int maximum = *max_element(nums.begin(), nums.end());
int minimum = *min_element(nums.begin(), nums.end());
```

数组不能为空。

### accumulate()

计算元素总和：

```cpp
#include <numeric>

long long sum = accumulate(nums.begin(), nums.end(), 0LL);
```

使用 `0LL` 可以让计算过程采用 `long long`，避免整数总和溢出。

## 十、常用函数汇总

| 函数 | 作用 | 常见复杂度 |
| --- | --- | --- |
| `push_back(value)` | 在末尾添加元素 | 平均 `O(1)` |
| `emplace_back(value)` | 在末尾直接构造元素 | 平均 `O(1)` |
| `pop_back()` | 删除最后一个元素 | `O(1)` |
| `insert(pos, value)` | 在指定位置前插入 | `O(n)` |
| `erase(pos)` | 删除指定位置 | `O(n)` |
| `clear()` | 删除所有元素 | `O(n)` |
| `size()` | 返回元素数量 | `O(1)` |
| `empty()` | 判断是否为空 | `O(1)` |
| `front()` | 访问第一个元素 | `O(1)` |
| `back()` | 访问最后一个元素 | `O(1)` |
| `at(index)` | 带越界检查地访问 | `O(1)` |
| `resize(n)` | 改变元素数量 | 与改变量有关 |
| `reserve(n)` | 提前申请容量 | 与重新分配有关 |
| `capacity()` | 返回当前容量 | `O(1)` |
| `begin()` / `end()` | 返回正向迭代器 | `O(1)` |
| `rbegin()` / `rend()` | 返回反向迭代器 | `O(1)` |

## 十一、常见易错点

1. `pop_back()` 只负责删除，不会返回被删除的元素。
2. `end()` 指向最后一个元素的后面，不能使用 `*nums.end()`。
3. `reserve()` 只改变容量，不改变元素数量；`resize()` 才会改变元素数量。
4. `erase()` 或中间位置的 `insert()` 可能让原来的迭代器失效。
5. 使用 `nums[i]` 前要保证 `0 <= i < nums.size()`。
6. `vector<vector<int>>` 表示二维数组，`vector<int>` 才表示一维数组。
