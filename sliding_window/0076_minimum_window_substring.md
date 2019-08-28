### [76\. Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/)

Difficulty: **Hard**


Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

**Example:**

```
Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"
```

**Note:**

*   If there is no such window in S that covers all characters in T, return the empty string `""`.
*   If there is such window, you are guaranteed that there will always be only one unique minimum window in S.


#### Solution

Language: **C++**

```c++
class Solution {
public:
    string minWindow(string s, string t) {
        
        // Count the characters in t
        int dict[128] = {0};
        for (auto & c : t)
            dict[c] ++;
        
        // Total number of characters needs to be matched
        int count = t.size();
        
        // Left and right pointers to specify the window
        int left = 0, right = 0;
        // Window size
        int d = INT_MAX;
        // head of the result substring
        int head = 0;
        
        // Expansion of the window
        while (right < s.size())
        {
            // Expand the window and check if the character appears in t
            if (dict[s[right++]]-- > 0)
                count--;
            
            // All characters matched
            // Contract the window by moving the left pointer
            while (count == 0)
            {
                // There exists a smaller window
                if (right-left < d)
                {
                    d = right-left;
                    head = left;
                }
                // Encounters a character that did not appear in t
                // This is the key, because if s[left] would be 0 after the increment, as it was originally negative after the right pointer passed by (i.e. initially not in the t)
                if (dict[s[left++]]++ == 0)
                    count++;
            }
        }
        
        return d == INT_MAX ? "" : s.substr(head,d);
    }
};

/*
string minWindow(string s, string t) {
	unordered_map<char, int> m;
	// Statistic for count of char in t
	for (auto c : t) m[c]++;
	// counter represents the number of chars of t to be found in s.
	size_t start = 0, end = 0, counter = t.size(), minStart = 0, minLen = INT_MAX;
	size_t size = s.size();

	// Move end to find a valid window.
	while (end < size) {
		// If char in s exists in t, decrease counter
		if (m[s[end]] > 0)
			counter--;
		// Decrease m[s[end]]. If char does not exist in t, m[s[end]] will be negative.
		m[s[end]]--;
		end++;
		// When we found a valid window, move start to find smaller window.
		while (counter == 0) {
			if (end - start < minLen) {
				minStart = start;
				minLen = end - start;
			}
			m[s[start]]++;
			// When char exists in t, increase counter.
			if (m[s[start]] > 0)
				counter++;
			start++;
		}
	}
	if (minLen != INT_MAX)
		return s.substr(minStart, minLen);
	return "";
}

*/

```
