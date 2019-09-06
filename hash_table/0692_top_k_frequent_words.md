### [692\. Top K Frequent Words](https://leetcode.com/problems/top-k-frequent-words/)

Difficulty: **Medium**


Given a non-empty list of words, return the _k_ most frequent elements.

Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.

**Example 1:**

```
Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
Output: ["i", "love"]
Explanation: "i" and "love" are the two most frequent words.
    Note that "i" comes before "love" due to a lower alphabetical order.
```

**Example 2:**

```
Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
Output: ["the", "is", "sunny", "day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
    with the number of occurrence being 4, 3, 2 and 1 respectively.
```

**Note:**

1.  You may assume _k_ is always valid, 1 ≤ _k_ ≤ number of unique elements.
2.  Input words contain only lowercase letters.

**Follow up:**

1.  Try to solve it in _O_(_n_ log _k_) time and _O_(_n_) extra space.


#### Solution

Language: **C++**

```c++
typedef pair<string,int> psi;
​
class Solution {
public:
    
    struct Comp
    {
        bool operator()(psi a, psi b)
        {
            if (a.second == b.second)
                return a.first > b.first;
            else
                return a.second < b.second;
        }
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        if (words.empty())
            return vector<string>{};
        
        unordered_map<string,int> counter;
        for (auto & w : words)
            counter[w] ++;
        
        priority_queue<psi,vector<psi>,Comp> pq;
        
        for (auto & p : counter)
            pq.push(p);
        
        vector<string> res;
        for (int i = 0; i < k; ++i)
        {
            psi top = pq.top();
            res.push_back(top.first);
            pq.pop();
        }
        
        return res;  
    }
};
```
