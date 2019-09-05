### [246\. Strobogrammatic Number](https://leetcode.com/problems/strobogrammatic-number/)

Difficulty: **Easy**


A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Write a function to determine if a number is strobogrammatic. The number is represented as a string.

**Example 1:**

```
Input:  "69"
Output: true
```

**Example 2:**

```
Input:  "88"
Output: true
```

**Example 3:**

```
Input:  "962"
Output: false
```


#### Solution

Language: **C++**

```c++
class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char,char> dict;
        dict['6'] = '9';
        dict['9'] = '6';
        dict['1'] = '1';
        dict['8'] = '8';
        dict['0'] = '0';
        
        string rev;
        
        for (int i = 0; i < num.size(); ++i)
        {
            if (!dict.count(num[i]))
                return false;
            rev += dict[num[i]];
        }
        
        reverse(rev.begin(),rev.end());
        
        return rev == num;
        
    }
};
```
