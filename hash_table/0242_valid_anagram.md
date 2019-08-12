### [242\. Valid Anagram](https://leetcode.com/problems/valid-anagram/)

Difficulty: **Easy**


Given two strings _s_ and _t _, write a function to determine if _t_ is an anagram of _s_.

**Example 1:**

```
Input: s = "anagram", t = "nagaram"
Output: true
```

**Example 2:**

```
Input: s = "rat", t = "car"
Output: false
```

**Note:**
You may assume the string contains only lowercase alphabets.

**Follow up:**
What if the inputs contain unicode characters? How would you adapt your solution to such case?


#### Solution

Language: **C++**

```c++
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        
        // arrays act like hash tables
        int a[26] = {0};
        int b[26] = {0};
        
        for (int i = 0; i < s.size();++i)
        {
            a[s[i]-'a']++;
            b[t[i]-'a']++;
        }
        
        for (int i = 0; i < 26; ++i)
        {
            if (a[i] != b[i])
                return false;
        }
        
        return true;
    
    }
};
```
