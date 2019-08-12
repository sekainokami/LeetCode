### [20\. Valid Parentheses](https://leetcode.com/problems/valid-parentheses/)

Difficulty: **Easy**


Given a string containing just the characters `'('`, `')'`, `'{'`, `'}'`, `'['` and `']'`, determine if the input string is valid.

An input string is valid if:

1.  Open brackets must be closed by the same type of brackets.
2.  Open brackets must be closed in the correct order.

Note that an empty string is also considered valid.

**Example 1:**

```
Input: "()"
Output: true
```

**Example 2:**

```
Input: "()[]{}"
Output: true
```

**Example 3:**

```
Input: "(]"
Output: false
```

**Example 4:**

```
Input: "([)]"
Output: false
```

**Example 5:**

```
Input: "{[]}"
Output: true
```


#### Solution

Language: **C++**

```c++
class Solution {
public:
    bool isValid(string s) {
        unordered_set<string> hash = {"()","[]","{}"};
        unordered_set<char> left = {'(','[','{'};
        stack<char> st;
        
        for (int i = 0; i < s.size(); ++i)
        {
            if (left.count(s[i]))
                st.push(s[i]);
            else
            {
                if (st.empty())
                    return false;
                
                if (hash.count(string(1,st.top())+string(1,s[i])) == 0)
                    st.push(s[i]);
                else
                    st.pop();
            }
        }    
        return st.empty();
    }
};
```
