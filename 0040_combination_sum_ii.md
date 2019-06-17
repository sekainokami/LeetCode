### [40\. Combination Sum II](https://leetcode.com/problems/combination-sum-ii/)

Difficulty: **Medium**


Given a collection of candidate numbers (`candidates`) and a target number (`target`), find all unique combinations in `candidates` where the candidate numbers sums to `target`.

Each number in `candidates` may only be used **once** in the combination.

**Note:**

*   All numbers (including `target`) will be positive integers.
*   The solution set must not contain duplicate combinations.

**Example 1:**

```
Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
```

**Example 2:**

```
Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]
```


#### Solution

Language: **C++**

```c++
class Solution {
public:
    
    vector<vector<int>> res;
    
    void solve(vector<int>& candidates, vector<int>& curr, int remain, int start)
    {
        if (remain < 0)
            return;
        if (remain == 0)
        {
            res.push_back(curr);
            return;
        }
        
        for (int i = start; i < candidates.size(); ++i)
        {
            curr.push_back(candidates[i]);
            // start from i+1 to prevent reuse the same element
            solve(candidates,curr,remain-candidates[i],i+1);
            curr.pop_back();
            // prevent duplicate combinations
            while (i < candidates.size()-1 && candidates[i] == candidates[i+1])
                i++;
        }
        
        
    }
    
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort(candidates.begin(),candidates.end());
        vector<int> curr;
        solve(candidates,curr,target,0);
        return res;
    }
};
```
