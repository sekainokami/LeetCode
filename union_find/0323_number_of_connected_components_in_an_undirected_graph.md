### [323\. Number of Connected Components in an Undirected Graph](https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/)

Difficulty: **Medium**


Given `n` nodes labeled from `0` to `n - 1` and a list of undirected edges (each edge is a pair of nodes), write a function to find the number of connected components in an undirected graph.

**Example 1:**

```
Input: n = 5 and edges = [[0, 1], [1, 2], [3, 4]]

     0          3
     |          |
     1 --- 2    4

Output: 2
```

**Example 2:**

```
Input: n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]]

     0           4
     |           |
     1 --- 2 --- 3

Output:  1
```

**Note:**
You can assume that no duplicate edges will appear in `edges`. Since all edges are undirected, `[0, 1]` is the same as `[1, 0]` and thus will not appear together in `edges`.


#### Solution

Language: **C++**

```c++
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
    
    // Union-find
    // 1. Find the root
    // 2. Union the edges to remove sets
        
    // Parents of each node
    vector<int> parents(n, -1);
    
    // At start, each node is in its own set
    int res = n;
        
    // Go through each edge
    for (auto &e: edges) {
        // Extract the current node and the node it is connected to
        int v1 = e[0], v2 = e[1];
        // Find the root of the current node
        while (parents[v1] >= 0) v1 = parents[v1];
        // Find the root of the connected node
        while (parents[v2] >= 0) v2 = parents[v2];
        // If the roots differ, union them together
        if (v1 != v2) {
            parents[v2] = v1;
        // One set has been removed
            res--;
        }
    }
    return res;  
    }
};
```
