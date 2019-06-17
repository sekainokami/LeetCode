### [39\. Combination Sum](https://leetcode.com/problems/combination-sum/)

Difficulty: **Medium**


Given a **set** of candidate numbers (`candidates`) **(without duplicates)** and a target number (`target`), find all unique combinations in `candidates` where the candidate numbers sums to `target`.

The **same** repeated number may be chosen from `candidates` unlimited number of times.

**Note:**

*   All numbers (including `target`) will be positive integers.
*   The solution set must not contain duplicate combinations.

**Example 1:**

```
Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]
```

**Example 2:**

```
Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
```


#### Solution

Language: **C++**

```c++
class Solution {
public:
    
    
    vector<vector<int>> res;
    
    void solve(vector<int>& candidates, vector<int>& curr, int remain,int start)
    {
        if (remain < 0)
            return;
        
        if (remain == 0)
        {
            res.push_back(curr);
            return;
        }
        
        // To be unique, cannot start from the beginning, (i = 0 makes dups)
        for (int i = start; i < candidates.size(); ++i)
        {
            curr.push_back(candidates[i]);
            solve(candidates,curr,remain-candidates[i],i);
            curr.pop_back();
        }
    
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<int> curr;
        solve(candidates,curr,target,0);
        return res;
        
        
    }
};
```
