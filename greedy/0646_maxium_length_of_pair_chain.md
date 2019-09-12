### [646\. Maximum Length of Pair Chain](https://leetcode.com/problems/maximum-length-of-pair-chain/)

Difficulty: **Medium**


You are given `n` pairs of numbers. In every pair, the first number is always smaller than the second number.

Now, we define a pair `(c, d)` can follow another pair `(a, b)` if and only if `b < c`. Chain of pairs can be formed in this fashion.

Given a set of pairs, find the length longest chain which can be formed. You needn't use up all the given pairs. You can select pairs in any order.

**Example 1:**

```
Input: [[1,2], [2,3], [3,4]]
Output: 2
Explanation: The longest chain is [1,2] -> [3,4]
```

**Note:**

1.  The number of given pairs will be in the range [1, 1000].


#### Solution

Language: **C++**

```c++
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        
        // Greedy
        // Choose a pair with smaller end time is better
        sort(pairs.begin(),pairs.end(),[](vector<int>& p1, vector<int>& p2){return p1[1] < p2[1];});
        
        int res = 1;
        
        for (int i = 0; i < pairs.size(); ++i)
        {
            int curr = 1;
            int b = pairs[i][1];
            for (int j = i + 1; j < pairs.size(); ++j)
            {
                if (b < pairs[j][0])
                {
                    curr ++;
                    b = pairs[j][1];
                }
            }
            
            res = max(res,curr);
        }
​
        return res;
        
    }
};
```
