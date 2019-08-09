### [136\. Single Number](https://leetcode.com/problems/single-number/)

Difficulty: **Easy**


Given a **non-empty** array of integers, every element appears _twice_ except for one. Find that single one.

**Note:**

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

**Example 1:**

```
Input: [2,2,1]
Output: 1
```

**Example 2:**

```
Input: [4,1,2,1,2]
Output: 4
```


#### Solution

Language: **C++**

```c++
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        // if a == b, a XOR b == 0
        int x = 0;
        for (auto & n : nums)
            x ^= n;
        return x;
    }
};
```
