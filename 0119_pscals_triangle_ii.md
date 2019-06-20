### [119\. Pascal's Triangle II](https://leetcode.com/problems/pascals-triangle-ii/)

Difficulty: **Easy**


Given a non-negative index _k_ where _k_ ≤ 33, return the _k_<sup>th</sup> index row of the Pascal's triangle.

Note that the row index starts from 0.

![](https://upload.wikimedia.org/wikipedia/commons/0/0d/PascalTriangleAnimated2.gif)
<small style="display: inline;">In Pascal's triangle, each number is the sum of the two numbers directly above it.</small>

**Example:**

```
Input: 3
Output: [1,3,3,1]
```

**Follow up:**

Could you optimize your algorithm to use only _O_(_k_) extra space?


#### Solution

Language: **C++**

```c++
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        if (rowIndex == 0)
            return {1};
        if (rowIndex == 1)
            return {1,1};
        
        vector<int> last = {1,1};
        vector<int> curr;
        
        for (int i = 2; i < rowIndex+1; ++i)
        {
            curr = vector<int>(i+1,0);
            curr[0] = 1;
            curr[curr.size()-1] = 1;
            for (int j = 1; j < last.size();++j)
            {
                curr[j] = last[j] + last[j-1];
            }
            last = curr;
        }
        
        
        return curr;
        
        
    }
};
```
