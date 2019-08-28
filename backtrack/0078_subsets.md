### [78\. Subsets](https://leetcode.com/problems/subsets/)

Difficulty: **Medium**


Given a set of **distinct** integers, _nums_, return all possible subsets (the power set).

**Note:** The solution set must not contain duplicate subsets.

**Example:**

```
Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
```


#### Solution

Language: **C++**

```c++
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> subsets;
        vector<int> subset;
        bt(nums,0,subset,subsets);
        return subsets;
    }
    
    void bt(vector<int>& nums, int start, vector<int> subset, vector<vector<int>>& subsets)
    {
        subsets.push_back(subset);
        for (int i = start; i < nums.size(); ++i)
        {
            subset.push_back(nums[i]);
            bt(nums,i+1,subset,subsets);
            subset.pop_back();
        }
    }
};
```
