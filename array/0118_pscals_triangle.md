### [118\. Pascal's Triangle](https://leetcode.com/problems/pascals-triangle/)

Difficulty: **Easy**


Given a non-negative integer _numRows_, generate the first _numRows_ of Pascal's triangle.

![](https://upload.wikimedia.org/wikipedia/commons/0/0d/PascalTriangleAnimated2.gif)
<small style="display: inline;">In Pascal's triangle, each number is the sum of the two numbers directly above it.</small>

**Example:**

```
Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
```


#### Solution

Language: **C++**

```c++
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        if (numRows == 0)
            return {};
        
        
        if (numRows == 1)
            return {{1}};
        if (numRows == 2)
            return {{1},{1,1}};
        
        vector<vector<int>> res = {{1},{1,1}};
​
        for (int i = 3; i < numRows+1; ++i)
        {
            vector<int> layer(i,0);
            layer[0] = 1;
            layer[layer.size()-1] = 1;
            vector<int> last = res.back();
            for (int j = 1; j < last.size(); ++j)
            {
                // Pattern here
                layer[j] = last[j] + last[j-1];
            }
            res.push_back(layer);
        }
        
        return res;
        
    }
};
```
