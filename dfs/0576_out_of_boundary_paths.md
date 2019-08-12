### [576\. Out of Boundary Paths](https://leetcode.com/problems/out-of-boundary-paths/)

Difficulty: **Medium**


There is an **m** by **n** grid with a ball. Given the start coordinate **(i,j)** of the ball, you can move the ball to **adjacent** cell or cross the grid boundary in four directions (up, down, left, right). However, you can **at most** move **N** times. Find out the number of paths to move the ball out of grid boundary. The answer may be very large, return it after mod 10<sup>9</sup> + 7.

**Example 1:**

```
Input: m = 2, n = 2, N = 2, i = 0, j = 0
Output: 6
Explanation:

```

**Example 2:**

```
Input: m = 1, n = 3, N = 3, i = 0, j = 1
Output: 12
Explanation:

```

**Note:**

1.  Once you move the ball out of boundary, you cannot move it back.
2.  The length and height of the grid is in range [1,50].
3.  N is in range [0,50].


#### Solution

Language: **C++**

```c++
class Solution {
​
int M = 1000000007;  
​
public:
    
    int solve(int m, int n, int N, int i, int j, int memo[55][55][55])
    {
        if (i == m || j == n || i < 0 || j < 0)
            return 1;
        if (N == 0)
            return 0;
        if (memo[i][j][N] >= 0)
            return memo[i][j][N];
        
        vector<vector<int>> dirs = {{-1,0},{0,-1},{1,0},{0,1}};
        long long int sum = 0;
        for (auto& d : dirs)
        {
            int dx = d[0], dy = d[1];
            int tmp = solve(m,n,N-1,i+dx,j+dy,memo) % M;
            sum += tmp;
        }
        memo[i][j][N] = sum % M;
        return memo[i][j][N];
    }
    
    
    int findPaths(int m, int n, int N, int i, int j) {
        
        int memo[55][55][55];
        memset(memo,-1,sizeof(memo));
        int ret = solve(m,n,N,i,j,memo);
        return ret;
    }
};
```
