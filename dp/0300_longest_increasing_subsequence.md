### [300\. Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/)

Difficulty: **Medium**


Given an unsorted array of integers, find the length of longest increasing subsequence.

**Example:**

```
Input: [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4\.
```

**Note:**

*   There may be more than one LIS combination, it is only necessary for you to return the length.
*   Your algorithm should run in O(_n<sup>2</sup>_) complexity.

**Follow up:** Could you improve it to O(_n_ log _n_) time complexity?


#### Solution

Language: **C++**

```c++
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() <= 1)
            return nums.size();
        
        vector<int> dp(nums.size(),1);
        
        for (int i = 1; i < nums.size(); ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (nums[i] > nums[j])
                    dp[i] = max(dp[i],dp[j]+1);
            }
        }
        
        
        return *max_element(dp.begin(),dp.end());
        
        
    }
};
```
