### [344\. Reverse String](https://leetcode.com/problems/reverse-string/)

Difficulty: **Easy**


Write a function that reverses a string. The input string is given as an array of characters `char[]`.

Do not allocate extra space for another array, you must do this by **modifying the input array ** with O(1) extra memory.

You may assume all the characters consist of .


**Example 1:**

```
Input: ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
```


**Example 2:**

```
Input: ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
```


#### Solution

Language: **C++**

```c++
class Solution {
public:
    void reverseString(vector<char>& s) {
        
        if (s.empty())
            return;
        
        int left = 0, right = s.size()-1;
        while(left < right)
        {
            swap(s[left++],s[right--]);
        }
        
    }
};
```
