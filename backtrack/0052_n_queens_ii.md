### [52\. N-Queens II](https://leetcode.com/problems/n-queens-ii/)

Difficulty: **Hard**


The _n_-queens puzzle is the problem of placing _n_ queens on an _n_×_n_ chessboard such that no two queens attack each other.

![](https://assets.leetcode.com/uploads/2018/10/12/8-queens.png)

Given an integer _n_, return the number of distinct solutions to the _n_-queens puzzle.

**Example:**

```
Input: 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown below.
[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
```


#### Solution

Language: **C++**

```c++
class Solution {
public:
    
    void solve(int row, int n, vector<string>& board, int& res)
    {
        if (row == n)
        {
            res ++;
            return;
        }
        
        for (int col = 0; col < board.size(); ++col)
        {
            if (isValid(row,col,n,board))
            {
                board[row][col] = 'Q';
                solve(row+1,n,board,res);
                board[row][col] = '.';
            }
        }
        
    }
    
    
    
    bool isValid(int row, int col, int n, vector<string>& board)
    {
        for (int i = 0; i < row; ++i)
        {
            if (board[i][col] == 'Q')
                return false;
        }
        
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
        {
            if (board[i][j] == 'Q')
                return false;
        }
        
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j)
        {
            if (board[i][j] == 'Q')
                return false;
        }
        
        return true;
    }
    
    int totalNQueens(int n) {
        int res = 0;
        vector<string> board(n,string(n,'.'));
        solve(0,n,board,res);
        return res;
    }
};
```
