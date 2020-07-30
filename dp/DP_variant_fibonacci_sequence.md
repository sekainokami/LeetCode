### [198\. House Robber](https://leetcode.com/problems/house-robber/)

Difficulty: **Easy**  

Related Topics: [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)


You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and **it will automatically contact the police if two adjacent houses were broken into on the same night**.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight **without alerting the police**.

**Example 1:**

```
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.
```

**Example 2:**

```
Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
             Total amount you can rob = 2 + 9 + 1 = 12.
```

**Constraints:**

*   `0 <= nums.length <= 100`
*   `0 <= nums[i] <= 400`


#### Solution

Language: **C++**

```c++
class Solution {
public:
    int solve(int index, vector<int>& nums,vector<int>& mem) {
        if (index < 0) return 0;
        if (mem[index] != -1) return mem[index];
​
        int res = max(nums[index] + solve(index-2,nums,mem),solve(index-1,nums,mem));
        mem[index] = res;
        return res;
    }
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int res = 0;
        vector<int> mem(nums.size(),-1);
        for (int i = 0; i < nums.size(); ++i) {
            res = max(res,solve(i,nums,mem));
        }
        
        return res;
        
    }
};
```