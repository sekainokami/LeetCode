### [525\. Contiguous Array](https://leetcode.com/problems/contiguous-array/)

Difficulty: **Medium**


Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1\.

**Example 1:**

```
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
```

**Example 2:**

```
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
```

**Note:** The length of the given binary array will not exceed 50,000.


#### Solution

Language: **C++**

```c++
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
    
        unordered_map<int,int> hash;
        int count = 0, ret = 0;
        hash[0] = -1;
        for (int i = 0; i < nums.size(); ++i)
        {
            count += nums[i] == 0 ? -1 : 1;
            if (hash.count(count))
                ret = max(ret,i-hash[count]);
            else
                hash[count] = i;
        }
        
        return ret;    
    }
};
```
