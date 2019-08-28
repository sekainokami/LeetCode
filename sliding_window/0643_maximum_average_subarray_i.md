### [643\. Maximum Average Subarray I](https://leetcode.com/problems/maximum-average-subarray-i/)

Difficulty: **Easy**


Given an array consisting of `n` integers, find the contiguous subarray of given length `k` that has the maximum average value. And you need to output the maximum average value.

**Example 1:**

```
Input: [1,12,-5,-6,50,3], k = 4
Output: 12.75
Explanation: Maximum average is (12-5-6+50)/4 = 51/4 = 12.75
```

**Note:**

1.  1 <= `k` <= `n` <= 30,000.
2.  Elements of the given array will be in the range [-10,000, 10,000].


#### Solution

Language: **C++**

```c++
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        // Sliding window
        int left = 0, right = 0;
        double s = 0.0;
        
        // Expand to the correct window size
        while (right < k)
        {
            s += nums[right];
            right ++;
        }
        
        // Move the window along the array and find the max sum
        double res = s;
        while (right < nums.size())
        {
            s += nums[right++];
            s -= nums[left++];
            res = max(res,s);
        }
        
        return res / k;
    }
};
```
