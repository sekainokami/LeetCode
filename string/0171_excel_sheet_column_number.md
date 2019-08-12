### [171\. Excel Sheet Column Number](https://leetcode.com/problems/excel-sheet-column-number/)

Difficulty: **Easy**


Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

```
    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28
    ...
```

**Example 1:**

```
Input: "A"
Output: 1
```

**Example 2:**

```
Input: "AB"
Output: 28
```

**Example 3:**

```
Input: "ZY"
Output: 701
```


#### Solution

Language: **C++**

```c++
class Solution {
public:
    int titleToNumber(string s) {
        
        // Think this as a 26-based number
​
        int res = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            // If 26 * res + s[i] first, would cause overflow
            res = 26 * res - 'A' + s[i] + 1;
        }
        return res;
​
        /* One-liner
        return accumulate(s.begin(),s.end(),0,
               [](int sum, char c) {return 26 * sum + (c-'A'+1);});
        */
    }
};
```
