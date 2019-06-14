### [200\. Number of Islands](https://leetcode.com/problems/number-of-islands/)

Difficulty: **Medium**


Given a 2d grid map of `'1'`s (land) and `'0'`s (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

**Example 1:**

```
Input:
11110
11010
11000
00000

Output: 1
```

**Example 2:**

```
Input:
11000
11000
00100
00011

Output: 3
```


#### Solution

Language: **C++**

```c++
class Solution {
public:
    
    void flood(vector<vector<char>>& grid, int i, int j)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size() ||
           grid[i][j] == '0')
            return;
​
        grid[i][j] = '0';
        
        flood(grid,i-1,j);
        flood(grid,i+1,j);
        flood(grid,i,j-1);
        flood(grid,i,j+1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        if (grid.empty())
            return 0;
        
        int res = 0, m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {  
                if (grid[i][j] == '1')
                {
                    res++;
                    flood(grid,i,j);
                }
            }
        }
        return res;
    }
};
```
