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
        
        int left = 0, right = height.size()-1, maxleft = 0, maxright = 0, ret = 0;
        
        while (left < right)
        {
            if (height[left] < height[right])
            {
                if (height[left] > maxleft)
                    maxleft = height[left];
                else
                {
                    ret += maxleft - height[left];
                    left++;
                }
            }
            else
            {
                if (height[right] > maxright)
                    maxright = height[right];
                else
                {
                    ret += maxright - height[right];
                    right--;
                }
            }
            
        }
        
        return ret;
    }
};
```
