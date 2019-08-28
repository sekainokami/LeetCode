### [763\. Partition Labels](https://leetcode.com/problems/partition-labels/)

Difficulty: **Medium**


A string `S` of lowercase letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

**Example 1:**

```
Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
```

**Note:**

1.  `S` will have length in range `[1, 500]`.
2.  `S` will consist of lowercase letters (`'a'` to `'z'`) only.


#### Solution

Language: **C++**

```c++
class Solution {
public:
    vector<int> partitionLabels(string S) {
        // Last time each letter appeared in the string
        int last_index[26] = {-1};
        for (int i = 0; i < S.size(); ++i)
            last_index[S[i]-'a'] = i;
        
        vector<int> res;
        
        // Start and end of the partition
        int start = 0, end = 0;
        for (int i = 0; i < S.size(); ++i)
        {
            // Key: the rightmost end of the letters visted so far
            end = max(end,last_index[S[i]-'a']);
            if (i == end)
            {
                res.push_back(end-start+1);
                start = end + 1;
            }
        }
        
        return res;
    }
};
```
