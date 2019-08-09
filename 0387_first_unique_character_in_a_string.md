### [387\. First Unique Character in a String](https://leetcode.com/problems/first-unique-character-in-a-string/)

Difficulty: **Easy**


Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

**Examples:**

```
s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
```

**Note:** You may assume the string contain only lowercase letters.


#### Solution

Language: **C++**

```c++
class Solution {
public:
    int firstUniqChar(string s) {
        
        int counter[26] = {};
        for (int i = 0; i < s.size(); ++i)
        {
            counter[s[i]-'a']++;
        }
        for (int i = 0; i < s.size(); ++i)
        {
            if (counter[s[i]-'a'] == 1)
                return i;
        }
        return -1;
    }
};
```
