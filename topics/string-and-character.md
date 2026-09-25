# 字符串与字符判断

## 遍历字符串

```cpp
for (char c : s) {
    // c 是字符串中的当前字符
}
```

## 使用 ASCII 范围判断字符类型

```cpp
if (c >= 'a' && c <= 'z') {
    // 小写字母
} else if (c >= 'A' && c <= 'Z') {
    // 大写字母
} else if (c >= '0' && c <= '9') {
    // 数字
} else {
    // 特殊字符
}
```

## 使用 cctype 函数

需要包含头文件：

```cpp
#include <cctype>
```

常用函数：

- `islower(c)`：是否为小写字母
- `isupper(c)`：是否为大写字母
- `isdigit(c)`：是否为数字
- `isalpha(c)`：是否为字母
- `isalnum(c)`：是否为字母或数字

## 注意

如果字符串中可能包含空格，应使用 `getline(cin, s)`。如果题目保证输入中没有空格，可以使用 `cin >> s`。
