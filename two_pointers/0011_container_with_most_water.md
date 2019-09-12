### [11\. Container With Most Water](https://leetcode.com/problems/container-with-most-water/)

Difficulty: **Medium**


Given _n_ non-negative integers _a<sub style="display: inline;">1</sub>_, _a<sub style="display: inline;">2</sub>_, ..., _a<sub style="display: inline;">n </sub>_, where each represents a point at coordinate (_i_, _a<sub style="display: inline;">i</sub>_). _n_ vertical lines are drawn such that the two endpoints of line _i_ is at (_i_, _a<sub style="display: inline;">i</sub>_) and (_i_, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

**Note: **You may not slant the container and _n_ is at least 2.

![](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/07/17/question_11.jpg)

<small style="display: inline;">The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49\.</small>

**Example:**

```
Input: [1,8,6,2,5,4,8,3,7]
Output: 49
```


#### Solution

Language: **C++**

```c++
class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int left = 0, right = height.size()-1;
        int res = 0;
        
        while (left < right)
        {
            int w = (right - left) * min(height[left],height[right]);
            res = max(res,w);
            
            if (height[left] <= height[right])
                left++;
            else
                right--;
        }
        
        
        return res;
    }
};
```
