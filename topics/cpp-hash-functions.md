# C++ 哈希常用函数

刷 LeetCode 最常用的是：

```cpp
#include <unordered_map>
#include <unordered_set>
```

## unordered_map

`unordered_map` 用来保存 `key -> value`。

```cpp
unordered_map<int, int> mp;
```

### 写入和更新

```cpp
mp[3] = 10;      // key 3 对应 value 10
mp[3]++;         // 频次统计常用写法
mp.insert({5, 1});
```

注意：`mp[key]` 如果 key 不存在，会自动创建一个默认值。

```cpp
unordered_map<int, int> mp;
cout << mp[100]; // 输出 0，同时创建 key 100
```

### 判断 key 是否存在

推荐刷题常用：

```cpp
if (mp.count(key)) {
    // key 存在
}
```

也可以用 `find`：

```cpp
if (mp.find(key) != mp.end()) {
    // key 存在
}
```

如果只是判断存在，不想自动插入 key，不要用 `mp[key]`。

### 读取 value

```cpp
int value = mp[key];
```

如果你不确定 key 是否存在，先判断：

```cpp
if (mp.count(key)) {
    int value = mp[key];
}
```

### 删除元素

```cpp
mp.erase(key);
```

### 遍历

```cpp
for (auto& [key, value] : mp) {
    cout << key << " " << value << endl;
}
```

旧写法：

```cpp
for (auto& p : mp) {
    cout << p.first << " " << p.second << endl;
}
```

### 常用属性

```cpp
mp.size();       // 元素个数
mp.empty();      // 是否为空
mp.clear();      // 清空
```

## unordered_set

`unordered_set` 用来保存不重复元素，只关心“有没有出现过”。

```cpp
unordered_set<int> st;
```

### 插入

```cpp
st.insert(x);
```

### 判断是否存在

```cpp
if (st.count(x)) {
    // x 出现过
}
```

或者：

```cpp
if (st.find(x) != st.end()) {
    // x 出现过
}
```

### 删除

```cpp
st.erase(x);
```

### 遍历

```cpp
for (int x : st) {
    cout << x << endl;
}
```

注意：`unordered_set` 的遍历顺序不固定。

## 刷题常用模板

### 模板一：Two Sum 查补数

```cpp
unordered_map<int, int> seen;

for (int i = 0; i < nums.size(); i++) {
    int need = target - nums[i];

    if (seen.count(need)) {
        return {seen[need], i};
    }

    seen[nums[i]] = i;
}
```

### 模板二：统计频次

```cpp
unordered_map<int, int> freq;

for (int x : nums) {
    freq[x]++;
}
```

找只出现一次的数字：

```cpp
for (auto& [num, count] : freq) {
    if (count == 1) {
        return num;
    }
}
```

### 模板三：检查重复

```cpp
unordered_set<int> seen;

for (int x : nums) {
    if (seen.count(x)) {
        return true;
    }
    seen.insert(x);
}

return false;
```

### 模板四：字符串字符频次

```cpp
vector<int> count(26, 0);

for (char c : s) {
    count[c - 'a']++;
}
```

如果字符范围只有小写字母，优先用数组，比哈希表更快。

## map 和 unordered_map 的区别

| 容器 | 是否有序 | 平均查找 | 常见用途 |
| --- | --- | --- | --- |
| `unordered_map` | 无序 | `O(1)` | 刷题最常用哈希表 |
| `map` | 按 key 有序 | `O(log n)` | 需要 key 有序时 |
| `unordered_set` | 无序 | `O(1)` | 判断是否出现过 |
| `set` | 按值有序 | `O(log n)` | 需要自动排序去重时 |

## 易错点

- `mp[key]` 会在 key 不存在时自动插入，判断存在时优先用 `count` 或 `find`。
- `unordered_map` 和 `unordered_set` 遍历顺序不固定。
- 如果 key 是自定义类型，需要自己写哈希函数。
- 如果只统计小写字母频次，用 `vector<int> count(26)` 通常更简单。
- `count(key)` 返回的是数量，对 `unordered_map` 来说只可能是 `0` 或 `1`。
