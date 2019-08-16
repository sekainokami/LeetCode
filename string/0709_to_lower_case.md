### [709\. To Lower Case](https://leetcode.com/problems/to-lower-case/)

Difficulty: **Easy**


Implement function ToLowerCase() that has a string parameter str, and returns the same string in lowercase.


**Example 1:**

```
Input: "Hello"
Output: "hello"
```


**Example 2:**

```
Input: "here"
Output: "here"
```


**Example 3:**

```
Input: "LOVELY"
Output: "lovely"
```


#### Solution

Language: **C++**

```c++
class Solution {
public:
    string toLowerCase(string str) {
        for (int i = 0; i < str.size(); ++i)
            str[i] = tolower(str[i]);
        return str;
    }
};
```
