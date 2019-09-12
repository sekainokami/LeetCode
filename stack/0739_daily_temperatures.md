### [739\. Daily Temperatures](https://leetcode.com/problems/daily-temperatures/)

Difficulty: **Medium**


Given a list of daily temperatures `T`, return a list such that, for each day in the input, tells you how many days you would have to wait until a warmer temperature. If there is no future day for which this is possible, put `0` instead.

For example, given the list of temperatures `T = [73, 74, 75, 71, 69, 72, 76, 73]`, your output should be `[1, 1, 4, 2, 1, 1, 0, 0]`.

**Note:** The length of `temperatures` will be in the range `[1, 30000]`. Each temperature will be an integer in the range `[30, 100]`.


#### Solution

Language: **C++**

```c++
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        // pair<int,int>: (temperture, index)
        stack<pair<int,int>> st;
        vector<int> res(T.size(),0);
        for (int i = 0; i < T.size(); ++i)
        {
            while (!st.empty() && T[i] > st.top().first)
            {
                res[st.top().second] = i - st.top().second;
                st.pop();
            }
            
            st.push(make_pair(T[i],i));
        }
        
        return res;
    }
};
```
