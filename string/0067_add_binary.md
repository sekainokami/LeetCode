### [67\. Add Binary](https://leetcode.com/problems/add-binary/)

Difficulty: **Easy**


Given two binary strings, return their sum (also a binary string).

The input strings are both **non-empty** and contains only characters `1` or `0`.

**Example 1:**

```
Input: a = "11", b = "1"
Output: "100"
```

**Example 2:**

```
Input: a = "1010", b = "1011"
Output: "10101"
```


#### Solution

Language: **C++**

```c++
class Solution {
public:
    string addBinary(string a, string b) {
        // Similar to add two linked lists
        int i = a.size()-1, j = b.size()-1;
        int carry = 0;
        string res;
        while (i >= 0 || j >=0 || carry)
        {
            int x = i >= 0 ? a[i]-'0' : 0;
            int y = j >= 0 ? b[j]-'0' : 0;
            int s = x + y + carry;
            carry = s / 2;
            s %= 2;
            
            res =  (char)(s + '0') + res;
            
            if (i >= 0) i--;
            if (j >= 0) j--;
        }
        
        return res;
        
    }
};
```
