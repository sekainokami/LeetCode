### [1061\. Lexicographically Smallest Equivalent String](https://leetcode.com/problems/lexicographically-smallest-equivalent-string/)

Difficulty: **Medium**


Given strings `A` and `B` of the same length, we say A[i] and B[i] are equivalent characters. For example, if `A = "abc"` and `B = "cde"`, then we have `'a' == 'c', 'b' == 'd', 'c' == 'e'`.

Equivalent characters follow the usual rules of any equivalence relation:

*   Reflexivity: 'a' == 'a'
*   Symmetry: 'a' == 'b' implies 'b' == 'a'
*   Transitivity: 'a' == 'b' and 'b' == 'c' implies 'a' == 'c'

For example, given the equivalency information from `A` and `B` above, `S = "eed"`, `"acd"`, and `"aab"` are equivalent strings, and `"aab"` is the lexicographically smallest equivalent string of `S`.

Return the lexicographically smallest equivalent string of `S` by using the equivalency information from `A` and `B`.

**Example 1:**

```
Input: A = "parker", B = "morris", S = "parser"
Output: "makkek"
Explanation: Based on the equivalency information in A and B, we can group their characters as [m,p], [a,o], [k,r,s], [e,i]. The characters in each group are equivalent and sorted in lexicographical order. So the answer is "makkek".
```

**Example 2:**

```
Input: A = "hello", B = "world", S = "hold"
Output: "hdld"
Explanation:  Based on the equivalency information in A and B, we can group their characters as [h,w], [d,e,o], [l,r]. So only the second letter 'o' in S is changed to 'd', the answer is "hdld".
```

**Example 3:**

```
Input: A = "leetcode", B = "programs", S = "sourcecode"
Output: "aauaaaaada"
Explanation:  We group the equivalent characters in A and B as [a,o,e,r,s,c], [l,p], [g,t] and [d,m], thus all letters in S except 'u' and 'd' are transformed to 'a', the answer is "aauaaaaada".
```

**Note:**

1.  String `A`, `B` and `S` consist of only lowercase English letters from `'a'` - `'z'`.
2.  The lengths of string `A`, `B` and `S` are between `1` and `1000`.
3.  String `A` and `B` are of the same length.


#### Solution

Language: **C++**

```c++
class Solution {
public:
    string smallestEquivalentString(string A, string B, string S) {
        
        // Union find the establish equivalent set
        // Use smaller char as the parent
        
        vector<int> parents(26,-1);
        
        for (int i = 0; i < A.size(); ++i)
        {
            int v1 = A[i]-'a';
            int v2 = B[i]-'a';
            while (parents[v1] >=0) v1 = parents[v1];
            while (parents[v2] >=0) v2 = parents[v2];
            if (v1 != v2)
            {
                if (v1 < v2)
                    parents[v2] = v1;
                else
                    parents[v1] = v2;
            }
        }
        
        string res;
        for (int i = 0; i < S.size(); ++i)
        {
            int v = S[i] - 'a';
            while (parents[v] >= 0) v = parents[v];
            res += (char)(v + 'a');
        }
        
        return res;
        
        
    }
};
```
