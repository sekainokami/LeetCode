### [1160\. Find Words That Can Be Formed by Characters](https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/)

Difficulty: **Easy**


You are given an array of strings `words` and a string `chars`.

A string is _good_ if it can be formed by characters from `chars` (each character can only be used once).

Return the sum of lengths of all good strings in `words`.

**Example 1:**

```
Input: words = ["cat","bt","hat","tree"], chars = "atach"
Output: 6
Explanation:
The strings that can be formed are "cat" and "hat" so the answer is 3 + 3 = 6.
```

**Example 2:**

```
Input: words = ["hello","world","leetcode"], chars = "welldonehoneyr"
Output: 10
Explanation:
The strings that can be formed are "hello" and "world" so the answer is 5 + 5 = 10.
```

<span style="display: inline;">**Note:**</span>

1.  `1 <= words.length <= 1000`
2.  `1 <= words[i].length, chars.length <= 100`
3.  All strings contain lowercase English letters only.


#### Solution

Language: **C++**

```c++
class Solution {
public:
    
    inline bool good(string& s, unordered_map<char,int> um)
    {
        for (int i = 0; i < s.size(); ++i)
        {
            if (um[s[i]] == 0)
                return false;
            else
               um[s[i]]--;
        }
        
        return true;
    }
    
    
    int countCharacters(vector<string>& words, string chars) {
​
        unordered_map<char,int> um;
        for (auto & c: chars)
        {
            um[c] ++;
        }
        
        int res = 0;
        for (auto & w : words)
        {
            if (good(w,um))
                res += w.size();
        }
        
        return res;
    }
};
```
