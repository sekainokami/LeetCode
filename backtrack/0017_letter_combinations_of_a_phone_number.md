### [17\. Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/)

Difficulty: **Medium**


Given a string containing digits from `2-9` inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

![](http://upload.wikimedia.org/wikipedia/commons/thumb/7/73/Telephone-keypad2.svg/200px-Telephone-keypad2.svg.png)

**Example:**

```
Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
```

**Note:**

Although the above answer is in lexicographical order, your answer could be in any order you want.


#### Solution

Language: **C++**

```c++
class Solution {
public:
    
    void solve(string& digits, string& curr,
               vector<string>& res, vector<string>& book)
    {
        if (curr.size() == digits.size())
        {
            res.push_back(curr);
            return;
        }
        
        int index = curr.size();
        string choices = book[digits[index]-'0'];
        for (int i = 0; i < choices.size(); ++i)
        {
            curr += choices[i];
            solve(digits,curr,res,book);
            curr.pop_back();
        }
    }
    
    
    vector<string> letterCombinations(string digits) {
        
        if (digits.empty()) return {};
        
        vector<string> book = {"","","abc","def",
                               "ghi","jkl","mno",
                               "pqrs","tuv","wxyz"};
        vector<string> res;
        string curr;
        solve(digits,curr,res,book);
        return res;
    }
};
```
