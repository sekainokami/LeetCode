### [54\. Spiral Matrix](https://leetcode.com/problems/spiral-matrix/)

Difficulty: **Medium**


Given a matrix of _m_ x _n_ elements (_m_ rows, _n_ columns), return all elements of the matrix in spiral order.

**Example 1:**

```
Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
```

**Example 2:**

```
Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
```


#### Solution

Language: **C++**

```c++
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return vector<int>{};
        
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<bool>> seen(m,vector<bool>(n,false));
        vector<vector<int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};
        int curr_dir = 0;
        int x = 0, y = 0, nextx, nexty;
        int count = m * n;
        
        vector<int> res;
        while (count--)
        {  
            seen[y][x] = true;
            res.push_back(matrix[y][x]);
            
            // Calculate the potential next step
            // Then verify if it is ok
            vector<int> dir = dirs[curr_dir];
            nextx = x + dir[1], nexty = y + dir[0];
            
            // Turn clockwise whenever met a seen element or out of bound
            if (nextx < 0 || nextx >= n ||
                nexty < 0 || nexty >= m || seen[nexty][nextx])
            {
                curr_dir = (curr_dir + 1) % 4;
                dir = dirs[curr_dir];
                nextx = x + dir[1], nexty = y + dir[0];
            }
            
            x = nextx;
            y = nexty;
            
        }
        
        return res;
        
    }
};
                nexty < 0 || nexty >= m || seen[nexty][nextx])
```
