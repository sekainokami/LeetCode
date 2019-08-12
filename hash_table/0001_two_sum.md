### [1. Two sum](https://leetcode.com/problems/two-sum/)

Difficulty: **Easy**


Given an array of integers, return **indices** of the two numbers such that they add up to a specific target.

You may assume that each input would have **_exactly_** one solution, and you may not use the _same_ element twice.

**Example:**

```
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
```


#### Solution

Language: **C++**

```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        // Map = [complement to look for : index]
        unordered_map<int,int> Map;
        
        for (int i = 0; i < nums.size(); ++i)
        {
            auto it = Map.find(nums[i]);
            if (it != Map.end())
            {
                return {it->second,i};
            }
            
            Map[target-nums[i]] = i;
        }
        
        return {};
        
    }
};
```
