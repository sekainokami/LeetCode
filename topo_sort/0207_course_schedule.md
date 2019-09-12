### [207\. Course Schedule](https://leetcode.com/problems/course-schedule/)

Difficulty: **Medium**


There are a total of _n_ courses you have to take, labeled from `0` to `n-1`.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: `[0,1]`

Given the total number of courses and a list of prerequisite **pairs**, is it possible for you to finish all courses?

**Example 1:**

```
Input: 2, [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take.
             To take course 1 you should have finished course 0\. So it is possible.
```

**Example 2:**

```
Input: 2, [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take.
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1\. So it is impossible.
```

**Note:**

1.  The input prerequisites is a graph represented by **a list of edges**, not adjacency matrices. Read more about .
2.  You may assume that there are no duplicate edges in the input prerequisites.


#### Solution

Language: **C++**

```c++
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> g(numCourses,vector<int>());
        vector<int> degrees(numCourses);
        for (auto & p: prerequisites)
        {
            if (p.size() > 1)
            {
                g[p[1]].push_back(p[0]);
                degrees[p[0]] ++;
            }
        }
        
        queue<int> q;
        for (int i = 0; i < degrees.size(); ++i)
        {
            if (degrees[i] == 0)
                q.push(i);
        }
        
        while (!q.empty())
        {
            int front = q.front();
            q.pop();
            numCourses--;
            for (int i = 0; i < g[front].size(); ++i)
            {
                int curr = g[front][i];
                degrees[curr]--;
                if (degrees[curr] == 0)
                    q.push(curr);
            }
        }
        
        return numCourses == 0;
        
    }
};
```
