### [547\. Friend Circles](https://leetcode.com/problems/friend-circles/)

Difficulty: **Medium**


There are **N** students in a class. Some of them are friends, while some are not. Their friendship is transitive in nature. For example, if A is a **direct** friend of B, and B is a **direct** friend of C, then A is an **indirect** friend of C. And we defined a friend circle is a group of students who are direct or indirect friends.

Given a **N*N** matrix **M** representing the friend relationship between students in the class. If M[i][j] = 1, then the i<sub style="display: inline;">th</sub> and j<sub style="display: inline;">th</sub> students are **direct** friends with each other, otherwise not. And you have to output the total number of friend circles among all the students.

**Example 1:**

```
Input:
[[1,1,0],
 [1,1,0],
 [0,0,1]]
Output: 2
Explanation:The 0th and 1st students are direct friends, so they are in a friend circle. The 2nd student himself is in a friend circle. So return 2.
```

**Example 2:**

```
Input:
[[1,1,0],
 [1,1,1],
 [0,1,1]]
Output: 1
Explanation:The 0th and 1st students are direct friends, the 1st and 2nd students are direct friends, so the 0th and 2nd students are indirect friends. All of them are in the same friend circle, so return 1.
```

**Note:**

1.  N is in range [1,200].
2.  M[i][i] = 1 for all students.
3.  If M[i][j] = 1, then M[j][i] = 1.


#### Solution

Language: **C++**

```c++
class Solution {
public:

    /* DFS
    void dfs(vector<vector<int>>& M, int i, vector<bool>& visited)
    {
        // Eliminate this friend
        visited[i] = true;
        // Further eliminate all friends of this friend
        for (int j = 0; j < M.size(); ++j)
        {
            // jth is the current friend of ith
            // jth also has not been eliminated
            if (M[i][j] && !visited[j])
                dfs(M,j,visited);
        }
    }

    int findCircleNum(vector<vector<int>>& M) {
        int res = 0, n = M.size();
        vector<bool> visited(n,false);

        // For every person not visited
        // Eliminate all of its friends
        for (int i = 0; i < n; ++i)
        {
            if (!visited[i])
            {
                dfs(M,i,visited);
                res ++;
            }
        }

        return res;
    }

    */

    /* BFS
    int findCircleNum(vector<vector<int>>& M) {
        int res = 0, n = M.size();
        vector<bool> visited(n,false);
        queue<int> Q;
        for (int i = 0; i < n; ++i)
        {
            if (!visited[i])
            {
                Q.push(i);
                while (!Q.empty())
                {
                    int front = Q.front();
                    Q.pop();
                    visited[front] = true;
                    for (int j = 0; j < n; ++j)
                    {
                        if (M[front][j] && !visited[j])
                            Q.push(j);
                    }
                }

                res ++;
            }
        }

        return res;

    }
    */


    // Union-find
    int get_root(vector<int>& root, int i)
    {
        // When it has not reached its root
        while (i != root[i])
        {
            // Update current root to root's root
            root[i] = root[root[i]];
            // Current position updated to the original root
            i = root[i];
        }

        return i;
    }


    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        // Initially, each number is its own set
        int res = n;
        // root[i] stores the root position for i
        vector<int> root(n);
        // Initially, the root of each node is itself
        for (int i = 0; i < n; ++i)
            root[i] = i;

        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                // i and j are known to be friends to each other
                if (M[i][j])
                {
                    int pi = get_root(root,i);
                    int pj = get_root(root,j);
                    // If friends' roots differ, union the root
                    // Also reduce the number of sets
                    if (pi != pj)
                    {
                        res --;
                        root[pj] = pi;
                    }
                }
            }
        }

        return res;

    }
};
```
