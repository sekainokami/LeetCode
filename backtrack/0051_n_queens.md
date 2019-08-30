### [51\. N-Queens](https://leetcode.com/problems/n-queens/)

Difficulty: **Hard**


The _n_-queens puzzle is the problem of placing _n_ queens on an _n_×_n_ chessboard such that no two queens attack each other.

![](https://assets.leetcode.com/uploads/2018/10/12/8-queens.png)

Given an integer _n_, return all distinct solutions to the _n_-queens puzzle.

Each solution contains a distinct board configuration of the _n_-queens' placement, where `'Q'` and `'.'` both indicate a queen and an empty space respectively.

**Example:**

```
Input: 4
Output: [
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.
```


#### Solution

Language: **C++**

```c++
class Solution {
private:
    void solve(int row, int n, vector<string>& board, vector<vector<string>>& res)
    {
        // Placed in all rows without failure, store the results
        if (row == n)
        {
            res.push_back(board);
            return;
        }
        
        // Place along each column
        for (int col = 0; col < board.size(); ++col)
        {
            if (isValid(row,col,n,board))
            {
                board[row][col] = 'Q';
                solve(row+1,n,board,res);
                // backtrack
                board[row][col] = '.';
            }
        }
    }
    
    bool isValid(int row, int col, int n, vector<string>& board)
    {
        // Check each row before
        for (int i = 0; i < row; ++i)
        {
            if (board[i][col] == 'Q')
                return false;
        }
        
        // Check top left (135-degree)
        for (int i = row-1, j = col-1; i >=0 && j >=0; --i, --j)
        {
            if (board[i][j] == 'Q')
                return false;
        }
        
        // Check top right (45-degree)
        for (int i = row-1, j = col+1; i >=0 && j<n; --i, ++j)
        {
            if (board[i][j] == 'Q')
                return false;
        }
        
        return true;
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n,string(n,'.'));
        solve(0,n,board,res);
        return res;
    }
};
```
