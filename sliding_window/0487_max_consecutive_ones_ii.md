### [487\. Max Consecutive Ones II](https://leetcode.com/problems/max-consecutive-ones-ii/)

Difficulty: **Medium**


Given a binary array, find the maximum number of consecutive 1s in this array if you can flip at most one 0.

**Example 1:**  

```
Input: [1,0,1,1,0]
Output: 4
Explanation: Flip the first zero will get the the maximum number of consecutive 1s.
    After flipping, the maximum number of consecutive 1s is 4.
```

**Note:**

*   The input array will only contain `0` and `1`.
*   The length of input array is a positive integer and will not exceed 10,000

**Follow up:**  
What if the input numbers come in one by one as an **infinite stream**? In other words, you can't store all numbers coming from the stream as it's too large to hold in memory. Could you solve it efficiently?


#### Solution

Language: **C++**

```c++
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        // j tries to get away from i as much as possible
        int i = 0,j;
        int k = 1;
        for (j = 0; j < nums.size(); ++j) {
            // lose credit
            if (nums[j] == 0)
                k--;
            // get credit
            if (k < 0 && nums[i++] == 0)
                k++;
            
            // if k is negative, then i and j move together
            // so the window does not change
            // if k is non-negative, then j can expand further
        }
        
        return j - i;
    }
};
```
