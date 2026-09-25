# 二分查找

## 题型信号

- 有序数组。
- 答案具有单调性。
- 问最小可行值、最大可行值。

## 模板

```python
left, right = 0, len(nums) - 1

while left <= right:
    mid = (left + right) // 2
    if nums[mid] == target:
        return mid
    if nums[mid] < target:
        left = mid + 1
    else:
        right = mid - 1

return -1
```

## 高频题

| 题号 | 题目 | 备注 |
| --- | --- | --- |
| 0704 | Binary Search | 基础模板 |
| 0035 | Search Insert Position | 插入位置 |
| 0153 | Find Minimum in Rotated Sorted Array | 旋转数组 |

