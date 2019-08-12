### [46\. Permutations](https://leetcode.com/problems/permutations/)

Difficulty: **Medium**


Given a collection of **distinct** integers, return all possible permutations.

**Example:**

```
Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
```


#### Solution

Language: **C++**

```c++
class Solution {
public:
​
    // Permutation is just to swap every element with all other elements
    // right to it
    void solve(vector<vector<int>>& res, vector<int>& nums, int start)
    {
        if (start == nums.size())
        {
            res.push_back(nums);
        }
        
        for (int i = start; i < nums.size(); ++i)
        {
            swap(nums[start],nums[i]);
            // swap with the next element
            solve(res,nums,start+1);
            // backtrack to the origin state
            swap(nums[start],nums[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        solve(res,nums,0);
        return res;
        
    }
};
```
