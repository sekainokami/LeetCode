### [69\. Sqrt(x)](https://leetcode.com/problems/sqrtx/)

Difficulty: **Easy**


Implement `int sqrt(int x)`.

Compute and return the square root of _x_, where _x_ is guaranteed to be a non-negative integer.

Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

**Example 1:**

```
Input: 4
Output: 2
```

**Example 2:**

```
Input: 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since
             the decimal part is truncated, 2 is returned.
```


#### Solution

Language: **C++**

```c++
class Solution {
public:
    int mySqrt(int x) {
        
        if (x < 2) return x;
        
        int low = 0;
        int high = x > 4 ? x / 2 : x;
        
        while (low <= high)
        {
            int mid = (high - low) / 2 + low;
            if (x / mid == mid)
                return mid;
            // Divded a number that's too small
            else if (x / mid > mid)
                low = mid + 1;
            else
                high = mid - 1;
        }
        // Check if the number is too big
        return x / low < low ? low - 1 : low;
        
    }
};
```
