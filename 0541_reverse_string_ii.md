### [541\. Reverse String IICopy for MarkdownCopy for Markdown](https://leetcode.com/problems/reverse-string-ii/)

Difficulty: **Easy**

Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from the start of the string. If there are less than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and left the other as original.

**Example:**

```
Input: s = "abcdefg", k = 2
Output: "bacdfeg"
```

**Restrictions:**

1.  The string consists of lower English letters only.
2.  Length of the given string and k will in the range [1, 10000]


#### Solution

Language: **C++**

```c++
class Solution {
public:
    
    // Swap a segment of the string between start and stop
    void swap(string& s, int start, int stop)
    {
        while (start < stop)
        {
            std::swap(s[start++],s[stop--]);
        }
    }
    
    
    string reverseStr(string s, int k) {
        
        int start = 0;
        int n = s.size();
        while (start < s.size())
        {
            int stop = min(n-1,start+k-1);
            swap(s,start,stop);
            start += 2 * k;
        }
        
        return s;
        
    }
};
```
