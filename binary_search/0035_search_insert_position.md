### [35\. Search Insert Position](https://leetcode.com/problems/search-insert-position/)

Difficulty: **Easy**


Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

**Example 1:**

```
Input: [1,3,5,6], 5
Output: 2
```

**Example 2:**

```
Input: [1,3,5,6], 2
Output: 1
```

**Example 3:**

```
Input: [1,3,5,6], 7
Output: 4
```

**Example 4:**

```
Input: [1,3,5,6], 0
Output: 0
```


#### Solution

Language: **C++**

```c++
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        int mid = 0;
        
        if (target < nums.front())
            return 0;
        else if (target > nums.back())
            return nums.size();
        
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid -1;
        }
        
        if (target > nums[mid])
            return mid + 1;
        else
            return mid;
    }
};
```
