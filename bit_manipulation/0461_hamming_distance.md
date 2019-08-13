### [461\. Hamming Distance](https://leetcode.com/problems/hamming-distance/)

Difficulty: **Easy**


The between two integers is the number of positions at which the corresponding bits are different.

Given two integers `x` and `y`, calculate the Hamming distance.

**Note:**
0 ≤ `x`, `y` < 2<sup>31</sup>.

**Example:**

```
Input: x = 1, y = 4

Output: 2

Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑

The above arrows point to positions where the corresponding bits are different.
```


#### Solution

Language: **C++**

```c++
class Solution {
public:
    int hammingDistance(int x, int y) {
        int z = x ^ y;
        int res = 0;
        while (z)
        {
            z &= (z-1);
            res ++;
        }
        return res;
    }
};
```
