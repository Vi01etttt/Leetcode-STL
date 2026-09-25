# string：字符串

头文件：`#include <string>`。`string` 支持下标访问、末尾追加、查找和截取子串。

```cpp
string s = "abc";
char first = s[0];              // 'a'
s.push_back('d');               // "abcd"
s += "ef";                      // "abcdef"
s.pop_back();                   // "abcde"
```

| 用法 | 含义 |
| --- | --- |
| `s.size()` / `s.length()` | 字符数量 |
| `s.empty()` | 是否为空 |
| `s[i]` | 访问或修改第 i 个字符，不检查越界 |
| `s.at(i)` | 带越界检查地访问 |
| `s.front()` / `s.back()` | 第一个 / 最后一个字符，非空时使用 |
| `s.substr(pos, len)` | 从下标 `pos` 开始截取至多 `len` 个字符 |
| `s.find("bc")` | 查找子串，返回首次出现的下标 |
| `s.erase(pos, len)` | 从下标 `pos` 起删除至多 `len` 个字符 |
| `s.insert(pos, "hi")` | 在下标 `pos` 前插入字符串 |
| `s.clear()` | 清空字符串 |

查找时要判断是否找到：

```cpp
auto pos = s.find("bc");
if (pos != string::npos) {
    // 找到了，下标是 pos
}
```

`substr` 的第二个参数是**长度**，不是结束下标。`find` 找不到时返回 `string::npos`。题目允许空格时用 `getline(cin, s)` 读整行；`cin >> s` 会在空白处分隔。
