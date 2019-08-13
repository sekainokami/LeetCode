### [1108\. Defanging an IP Address](https://leetcode.com/problems/defanging-an-ip-address/)

Difficulty: **Easy**


Given a valid (IPv4) IP `address`, return a defanged version of that IP address.

A _defanged IP address_ replaces every period `"."` with `"[.]"`.

**Example 1:**

```
Input: address = "1.1.1.1"
Output: "1[.]1[.]1[.]1"
```

**Example 2:**

```
Input: address = "255.100.50.0"
Output: "255[.]100[.]50[.]0"
```

**Constraints:**

*   The given `address` is a valid IPv4 address.


#### Solution

Language: **C++**

```c++
class Solution {
public:
    string defangIPaddr(string address) {
        string res;
        for (int i = 0; i < address.size(); ++i)
        {
            if (address[i] == '.')
                res += "[.]";
            else
                res += string(1,address[i]);
        }
        
        return res;
    }
};
```
