### [3\. Longest Substring Without Repeating CharactersCopy for MarkdownCopy for Markdown](https://leetcode.com/problems/longest-substring-without-repeating-characters/)

Difficulty: **Medium**


Given a string, find the length of the **longest substring** without repeating characters.


**Example 1:**

```
Input: "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3\.
```


**Example 2:**

```
Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
```


**Example 3:**

```
Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3\.
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
```


#### Solution

Language: **C++**

```c++
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0, res = 0;
        unordered_set<char> hash;
        
        while (left < s.size() && right < s.size())
        {
            if (hash.count(s[right]))
                hash.erase(s[left++]);
            else
            {
                hash.insert(s[right++]);
                res = max(res,right-left);
            }
        }
        
        return res;
    }
};
```
