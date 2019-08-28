### [53\. Maximum Subarray](https://leetcode.com/problems/maximum-subarray/)

Difficulty: **Easy**


Given an integer array `nums`, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

**Example:**

```
Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
```

**Follow up:**

If you have figured out the O(_n_) solution, try coding another solution using the divide and conquer approach, which is more subtle.


#### Solution

Language: **C++**

```c++
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        
        int curr = nums[0];
        int res = nums[0];
        
        for (int i = 1; i < nums.size(); ++i)
        {
            // If the current sum is negative, just start from fresh
            if (curr < 0)
                curr = nums[i];
            else
                curr += nums[i];
            
            res = max(res,curr);
        }
        
        return res;
    }
};
```
