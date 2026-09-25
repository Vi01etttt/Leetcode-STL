# 复盘记录

## 核心模板

扫描字符串，并使用多个布尔变量记录不同条件是否出现：

```cpp
bool hasLower = false;
bool hasUpper = false;
bool hasDigit = false;
bool hasSpecial = false;
```

## 一刷

- 关键点：先判断长度，再统计字符类型。
- 字符类型数量可以通过四个 `bool` 直接相加得到。
