### [1119\. Remove Vowels from a String](https://leetcode.com/problems/remove-vowels-from-a-string/)

Difficulty: **Easy**


Given a string `S`, remove the vowels `'a'`, `'e'`, `'i'`, `'o'`, and `'u'` from it, and return the new string.

**Example 1:**

```
Input: "leetcodeisacommunityforcoders"
Output: "ltcdscmmntyfrcdrs"
```

**Example 2:**

```
Input: "aeiou"
Output: ""
```

**Note:**

1.  `S` consists of lowercase English letters only.
2.  `1 <= S.length <= 1000`


#### Solution

Language: **C++**

```c++
class Solution {
public:
    string removeVowels(string S) {
        unordered_set<char> vowels = {'a','e','i','o','u'};
        string s;
        for (int i = 0; i < S.size(); ++i)
            if (!vowels.count(S[i]))
                s += string(1,S[i]);
        
        return s;
    }
};
```
