### [201\. Bitwise AND of Numbers Range](https://leetcode.com/problems/bitwise-and-of-numbers-range/)

Difficulty: **Medium**


Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

**Example 1:**

```
Input: [5,7]
Output: 4
```

**Example 2:**

```
Input: [0,1]
Output: 0
```


#### Solution

Language: **C++**

```c++
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        return n > m ? rangeBitwiseAnd(m/2,n/2) << 1 : m;
    }
};
```
