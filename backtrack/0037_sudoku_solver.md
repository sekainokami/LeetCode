### [37\. Sudoku SolverCopy for MarkdownCopy for Markdown](https://leetcode.com/problems/sudoku-solver/)

Difficulty: **Hard**


Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy **all of the following rules**:

1.  Each of the digits `1-9` must occur exactly once in each row.
2.  Each of the digits `1-9` must occur exactly once in each column.
3.  Each of the the digits `1-9` must occur exactly once in each of the 9 `3x3` sub-boxes of the grid.

Empty cells are indicated by the character `'.'`.

![](https://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Sudoku-by-L2G-20050714.svg/250px-Sudoku-by-L2G-20050714.svg.png)  
<small style="display: inline;">A sudoku puzzle...</small>

![](https://upload.wikimedia.org/wikipedia/commons/thumb/3/31/Sudoku-by-L2G-20050714_solution.svg/250px-Sudoku-by-L2G-20050714_solution.svg.png)  
<small style="display: inline;">...and its solution numbers marked in red.</small>

**Note:**

*   The given board contain only digits `1-9` and the character `'.'`.
*   You may assume that the given Sudoku puzzle will have a single unique solution.
*   The given board size is always `9x9`.


#### Solution

Language: **C++**

```c++
class Solution {
    struct cell // encapsulates a single cell on a Sudoku board
    {
        uint8_t value; // cell value 1..9 or 0 if unset
        // number of possible (unconstrained) values for the cell
        uint8_t numPossibilities;
        // if bitset[v] is 1 then value can't be v
        bitset<10> constraints;
        cell() : value(0), numPossibilities(9),constraints() {};
    };
    array<array<cell,9>,9> cells;
​
    // sets the value of the cell to [v]
    // the function also propagates constraints to other cells and deduce new values where possible
    bool set(int i, int j, int v)
    {
        // updating state of the cell
        cell& c = cells[i][j];
        if (c.value == v)
            return true;
        if (c.constraints[v])
            return false;
        c.constraints = bitset<10>(0x3FE); // all 1s
        c.constraints.reset(v);
        c.numPossibilities = 1;
        c.value = v;
​
        // propagating constraints
        for (int k = 0; k<9; k++) {
            // to the row:
            if (i != k && !updateConstraints(k, j, v))
                return false;
            // to the column:
            if (j != k && !updateConstraints(i, k, v))
                return false;
            // to the 3x3 square:
            int ix = (i / 3) * 3 + k / 3;
            int jx = (j / 3) * 3 + k % 3;
            if (ix != i && jx != j && !updateConstraints(ix, jx, v))
        uint8_t value; // cell value 1..9 or 0 if unset
```
