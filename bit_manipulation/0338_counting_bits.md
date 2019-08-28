### [338\. Counting Bits](https://leetcode.com/problems/counting-bits/)

Difficulty: **Medium**


Given a non negative integer number **num**. For every numbers **i** in the range **0 ≤ i ≤ num** calculate the number of 1's in their binary representation and return them as an array.

**Example 1:**

```
Input: 2
Output: [0,1,1]```

**Example 2:**

```
Input: 5
Output: [0,1,1,2,1,2]
```

**Follow up:**

*   It is very easy to come up with a solution with run time **O(n*sizeof(integer))**. But can you do it in linear time **O(n)** /possibly in a single pass?
*   Space complexity should be **O(n)**.
*   Can you do it like a boss? Do it without using any builtin function like **__builtin_popcount** in c++ or in any other language.


#### Solution

Language: **C++**

```c++
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num+1,0);
        for (int i = 0; i <= num; ++i)
        {
            res[i] = helper(i);
        }
        
        return res;
    }
    
    int helper(int n)
    {
        int count = 0;
        while (n)
        {
            n &= n -1;
            count++;
        }
        return count;
    }
    
};
```
