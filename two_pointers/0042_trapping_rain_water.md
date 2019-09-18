### [42\. Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/)

Difficulty: **Hard**


Given _n_ non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

![](https://assets.leetcode.com/uploads/2018/10/22/rainwatertrap.png)
<small style="display: inline;">The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. **Thanks Marcos** for contributing this image!</small>

**Example:**

```
Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
```


#### Solution

Language: **C++**

```c++
class Solution {
public:
    int trap(vector<int>& height) {
        int left_max = 0, right_max = 0;
        int left = 0, right = height.size()-1;
        int res = 0;
        
        while (left < right)
        {
            // Left height limits
            if (height[left] < height[right])
            {
                // Water floods out to left
                if (height[left] > left_max)
                    left_max = height[left];
                // Accumulate water
                else
                    res += left_max - height[left++];
            }
            // Right height limits
            else
            {
                // Water floods out to right
                if (height[right] > right_max)
                    right_max = height[right];
                // Accumulate water
                else
                    res += right_max - height[right--];  
            }
        }
        
        return res;
    }
};
```
