### [283\. Move Zeroes](https://leetcode.com/problems/move-zeroes/)

Difficulty: **Easy**


Given an array `nums`, write a function to move all `0`'s to the end of it while maintaining the relative order of the non-zero elements.

**Example:**

```
Input: [0,1,0,3,12]
Output: [1,3,12,0,0]```

**Note**:

1.  You must do this **in-place** without making a copy of the array.
2.  Minimize the total number of operations.


#### Solution

Language: **C++**

```c++
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // Two pointers
        // The slow pointer only increments when a non-zero is added
        // The fast pointer traverses to search for the next non-zero
        for (int slow = 0, fast = 0; fast < nums.size(); ++fast)
        {
            if (nums[fast] != 0)
                swap(nums[slow++],nums[fast]);
        }
    }
};
```
