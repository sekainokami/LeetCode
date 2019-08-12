### [422\. Valid Word Square](https://leetcode.com/problems/valid-word-square/)

Difficulty: **Easy**


Given a sequence of words, check whether it forms a valid word square.

A sequence of words forms a valid word square if the _k_<sup>th</sup> row and column read the exact same string, where 0 ≤ _k_ < max(numRows, numColumns).

**Note:**

1.  The number of words given is at least 1 and does not exceed 500.
2.  Word length will be at least 1 and does not exceed 500.
3.  Each word contains only lowercase English alphabet `a-z`.

**Example 1:**

```
Input:
[
  "abcd",
  "bnrt",
  "crmy",
  "dtye"
]

Output:
true

Explanation:
The first row and first column both read "abcd".
The second row and second column both read "bnrt".
The third row and third column both read "crmy".
The fourth row and fourth column both read "dtye".

Therefore, it is a valid word square.
```

**Example 2:**

```
Input:
[
  "abcd",
  "bnrt",
  "crm",
  "dt"
]

Output:
true

Explanation:
The first row and first column both read "abcd".
The second row and second column both read "bnrt".
The third row and third column both read "crm".
The fourth row and fourth column both read "dt".

Therefore, it is a valid word square.
```

**Example 3:**

```
Input:
[
  "ball",
  "area",
  "read",
  "lady"
]

Output:
false

Explanation:
The third row reads "read" while the third column reads "lead".

Therefore, it is NOT a valid word square.
```


#### Solution

Language: **C++**

```c++
class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        
        
        size_t max_len = 0;
        for (auto & w: words)
            max_len = max(max_len,w.size());
        
        if (words.size() != max_len)
            return false;
        
        vector<string> rotated(max_len,"");
        
        for (auto & w : words)
        {
            for (int i = 0; i < w.size(); ++i)
                rotated[i] += string(1,w[i]);
        }
        
  
        for (int i = 0; i < max_len; ++i)
        {
            if (words[i] != rotated[i])
                return false;
        }
        
        return true;
        
    }
};
```
