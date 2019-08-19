### [34\. Find First and Last Position of Element in Sorted Array](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)

Difficulty: **Medium**


Given an array of integers `nums` sorted in ascending order, find the starting and ending position of a given `target` value.

Your algorithm's runtime complexity must be in the order of _O_(log _n_).

If the target is not found in the array, return `[-1, -1]`.

**Example 1:**

```
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]```

**Example 2:**

```
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]```


#### Solution

Language: **C++**

```c++
class Solution {
public:

    int find_first(vector<int>& nums, int target)
    {
        int res = -1;
        int l = 0, u = nums.size() - 1;
        while (l <= u)
        {
            int m = l + (u - l) / 2;
            if (nums[m] == target)
            {
                res = m;
                // keep search the left part
                u = m - 1;
            }
            else if (nums[m] < target)
                l = m + 1;
            else
                u = m - 1;
        }

        return res;
    }


    int find_last(vector<int>& nums, int target)
    {
        int res = -1;
        int l = 0, u = nums.size() - 1;
        while (l <= u)
        {
            int m = l + (u - l) / 2;
            if (nums[m] == target)
            {
                res = m;
                // keep search the right part
                l = m + 1;
            }
            else if (nums[m] < target)
                l = m + 1;
            else
                u = m - 1;
        }

        return res;
    }


    vector<int> searchRange(vector<int>& nums, int target) {

        vector<int> res(2,0);

        res[0] = find_first(nums,target);
        res[1] = find_last(nums,target);
        return res;

    }
};
```
