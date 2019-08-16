### [760\. Find Anagram Mappings](https://leetcode.com/problems/find-anagram-mappings/)

Difficulty: **Easy**


Given two lists `A`and `B`, and `B` is an anagram of `A`. `B` is an anagram of `A` means `B` is made by randomizing the order of the elements in `A`.

We want to find an _index mapping_ `P`, from `A` to `B`. A mapping `P[i] = j` means the `i`th element in `A` appears in `B` at index `j`.

These lists `A` and `B` may contain duplicates. If there are multiple answers, output any of them.

For example, given

```
A = [12, 28, 46, 32, 50]
B = [50, 12, 32, 46, 28]
```

We should return

```
[1, 4, 3, 2, 0]
```

as `P[0] = 1` because the `0`th element of `A` appears at `B[1]`, and `P[1] = 4` because the `1`st element of `A` appears at `B[4]`, and so on.

**Note:**

1.  `A, B` have equal lengths in range `[1, 100]`.
2.  `A[i], B[i]` are integers in range `[0, 10^5]`.


#### Solution

Language: **C++**

```c++
class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        unordered_map<int,int> m;
        vector<int> res(A.size(),0);
        for (int i = 0; i < B.size(); ++i)
            m[B[i]] = i;
        for (int j = 0; j < A.size(); ++j)
        {
            res[j] = m[A[j]];
        }
        return res;
    }
};
```
