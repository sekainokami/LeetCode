### [73\. Set Matrix Zeroes](https://leetcode.com/problems/set-matrix-zeroes/)

Difficulty: **Medium**


Given a _m_ x _n_ matrix, if an element is 0, set its entire row and column to 0\. Do it .

**Example 1:**

```
Input:
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output:
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
```

**Example 2:**

```
Input:
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
Output:
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]
```

**Follow up:**

*   A straight forward solution using O(_m__n_) space is probably a bad idea.
*   A simple improvement uses O(_m_ + _n_) space, but still not the best solution.
*   Could you devise a constant space solution?


#### Solution

Language: **C++**

```c++
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> killrow(m);
        vector<int> killcol(n);
        
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (matrix[i][j] == 0)
                {
                    killrow[i] = 1;
                    killcol[j] = 1;
                }
            }
        }
        
        for (int i = 0; i < m; ++i)
        {
            if (killrow[i])
            {
                for (int j = 0; j < n; ++j)
                    matrix[i][j] = 0;
            }
        }
        
        for (int j = 0; j < n; ++j)
        {
            if (killcol[j])
            {
                for (int i = 0; i < m; ++i)
                    matrix[i][j] = 0;
            }
        }
        
    }
};
```
