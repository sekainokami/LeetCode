### [1071\. Greatest Common Divisor of Strings](https://leetcode.com/problems/greatest-common-divisor-of-strings/)

Difficulty: **Easy**


For strings `S` and `T`, we say "`T` divides `S`" if and only if `S = T + ... + T`  (`T` concatenated with itself 1 or more times)

Return the largest string `X` such that `X` divides <font face="monospace" style="display: inline;">str1</font> and `X` divides <font face="monospace" style="display: inline;">str2</font>.

**Example 1:**

```
Input: str1 = "ABCABC", str2 = "ABC"
Output: "ABC"
```

**Example 2:**

```
Input: str1 = "ABABAB", str2 = "ABAB"
Output: "AB"
```

**Example 3:**

```
Input: str1 = "LEET", str2 = "CODE"
Output: ""
```

**Note:**

1.  `1 <= str1.length <= 1000`
2.  `1 <= str2.length <= 1000`
3.  `str1[i]` and `str2[i]` are English uppercase letters.


#### Solution

Language: **C++**

```c++
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        
        // cpp has internal gcd() function to get the gcd between 2 ints
        // This gcd must be the length of the result here
        // Otherwise the solution does not exist
        int a = gcd(str1.length(),str2.length());
        return str1.substr(0,a)==str2.substr(0,a)?str1.substr(0,a):"";
    }
};
```
