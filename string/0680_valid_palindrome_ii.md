### [680\. Valid Palindrome II](https://leetcode.com/problems/valid-palindrome-ii/)

Difficulty: **Easy**


Given a non-empty string `s`, you may delete **at most** one character. Judge whether you can make it a palindrome.

**Example 1:**

```
Input: "aba"
Output: True
```

**Example 2:**

```
Input: "abca"
Output: True
Explanation: You could delete the character 'c'.
```

**Note:**

1.  The string will only contain lowercase characters a-z. The maximum length of the string is 50000.


#### Solution

Language: **C++**

```c++
class Solution {
public:
    
    // Find the first unmatched characters
    // Delete either one of them to see if a palindrome can form
    
    
    inline bool isPal(string& s)
    {
        int i = 0, j = s.size()-1;
        while (i < j)
        {
            if (s[i++] != s[j--])
                return false;
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        
        int i = 0, j = s.size() -1;
        string a(s), b(s);
        
        while (i < j)
        {
            // Mismatch chars found
            if (s[i] != s[j])
            {
                a.erase(i,1);
                b.erase(j,1);
        while (i < j)
```
