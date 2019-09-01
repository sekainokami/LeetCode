### [289\. Game of Life](https://leetcode.com/problems/game-of-life/)

Difficulty: **Medium**


According to the : "The **Game of Life**, also known simply as **Life**, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

Given a _board_ with _m_ by _n_ cells, each cell has an initial state _live_ (1) or _dead_ (0). Each cell interacts with its (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

1.  Any live cell with fewer than two live neighbors dies, as if caused by under-population.
2.  Any live cell with two or three live neighbors lives on to the next generation.
3.  Any live cell with more than three live neighbors dies, as if by over-population..
4.  Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously.

**Example:**

```
Input:
[
  [0,1,0],
  [0,0,1],
  [1,1,1],
  [0,0,0]
]
Output:
[
  [0,0,0],
  [1,0,1],
  [0,1,1],
  [0,1,0]
]
```

**Follow up**:

1.  Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
2.  In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?


#### Solution

Language: **C++**

```c++
typedef pair<int,int> pii;
​
class Solution {
private:
    
    // Count number of living neighors
    inline int count(int i, int j, vector<vector<int>>& board)
    {
        // Out of bound: return 0
        if (i < 0 || i > board.size()-1 || j < 0 || j > board[i].size()-1)
            return 0;
        else
            return board[i][j];
    }
    
    // Check the fate of this cell
    int check(int i, int j, vector<vector<int>>& board)
    {
        int s = 0;
        s += count(i-1,j,board);
        s += count(i+1,j,board);
        s += count(i,j-1,board);
        s += count(i,j+1,board);
        s += count(i-1,j-1,board);
        s += count(i+1,j+1,board);
        s += count(i+1,j-1,board);
        s += count(i-1,j+1,board);
        
        // Living cell, check if can be dead
        if (board[i][j] == 1 && (s < 2 || s > 3))
            return 1;
        // Dead cell, check if can be alive
        else if (board[i][j] == 0 && s == 3)
            return 4;  
        return -1;
    }
    
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<pii> dead,alive;
        for (int i = 0; i < board.size();++i)
        {
            for (int j = 0; j < board[i].size();++j)
            {
                int d = check(i,j,board);
                if (d == 1)
                    dead.push_back(make_pair(i,j));
                else if (d == 4)
                    alive.push_back(make_pair(i,j));
            }
        }
        
        for (auto & p : dead)
            board[p.first][p.second] = 0;
        for (auto & p : alive)
            board[p.first][p.second] = 1;
    }
};
```
