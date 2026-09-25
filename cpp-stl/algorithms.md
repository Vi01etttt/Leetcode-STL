# 常和容器一起使用的算法函数

这些函数多数来自 `<algorithm>`，不是 `vector`、`string` 等容器的成员函数。下面的示例假设有 `vector<int> nums = {3, 1, 2, 2};`，并已包含 `<vector>`。

## 排序与反转

```cpp
#include <algorithm>
#include <functional>

sort(nums.begin(), nums.end());                 // [1, 2, 2, 3]
sort(nums.begin(), nums.end(), greater<int>()); // [3, 2, 2, 1]
reverse(nums.begin(), nums.end());              // 反转当前顺序
```

`sort` 的时间复杂度为 `O(n log n)`。`reverse` 为 `O(n)`。

## 查找与计数

```cpp
auto it = find(nums.begin(), nums.end(), 2);
if (it != nums.end()) {
    int value = *it;             // 找到的元素
}

int times = count(nums.begin(), nums.end(), 2);
```

`find` 和 `count` 都是线性扫描，时间复杂度为 `O(n)`。它们与 `unordered_map::find`、`unordered_map::count` 是不同的函数。

## 在有序数组中二分

```cpp
sort(nums.begin(), nums.end()); // 二分前先保证有序

auto left = lower_bound(nums.begin(), nums.end(), 2); // 第一个 >= 2
auto right = upper_bound(nums.begin(), nums.end(), 2); // 第一个 > 2

int firstIndex = static_cast<int>(left - nums.begin());
int occurrence = static_cast<int>(right - left);       // 2 的出现次数
```

若所有元素都小于目标值，迭代器可能等于 `nums.end()`，不能解引用。对 `vector` 的有序区间，二分查找是 `O(log n)`。

## 最值与求和

```cpp
#include <numeric>

if (!nums.empty()) {
    int biggest = *max_element(nums.begin(), nums.end());
    int smallest = *min_element(nums.begin(), nums.end());
}

long long total = accumulate(nums.begin(), nums.end(), 0LL);
```

`max_element` / `min_element` 返回迭代器，空数组不可解引用。`accumulate` 的初值写 `0LL` 时，累加过程用 `long long`，适合防止 `int` 求和溢出。

## 排序后去重

```cpp
sort(nums.begin(), nums.end());
nums.erase(unique(nums.begin(), nums.end()), nums.end());
```

`unique` 把去重后保留的元素整理到前面，并返回新的逻辑末尾；末尾剩余位置的值不要再依赖。真正缩短 `vector` 还要调用 `erase`。如果要把所有重复值都去掉，通常先排序，让相同值相邻。
