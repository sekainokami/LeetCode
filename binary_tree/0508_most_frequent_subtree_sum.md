### [508\. Most Frequent Subtree Sum](https://leetcode.com/problems/most-frequent-subtree-sum/)

Difficulty: **Medium**


Given the root of a tree, you are asked to find the most frequent subtree sum. The subtree sum of a node is defined as the sum of all the node values formed by the subtree rooted at that node (including the node itself). So what is the most frequent subtree sum value? If there is a tie, return all the values with the highest frequency in any order.

**Examples 1**
Input:

```
  5
 /  \
2   -3
```

return [2, -3, 4], since all the values happen only once, return all of them in any order.

**Examples 2**
Input:

```
  5
 /  \
2   -5
```

return [2], since 2 happens twice, however -5 only occur once.

**Note:** You may assume the sum of values in any subtree is in the range of 32-bit signed integer.


#### Solution

Language: **C++**

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    
private:
    unordered_map<int,int> counter;
    
    int solve(TreeNode* root)
    {
        if (root == nullptr)
            return 0;
        
        int s = root->val + solve(root->left) + solve(root->right);
        counter[s]++;
        return s;
    }
    
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        
    // 1. Find all the subtree sums
    // 2. Return the most frequent ones
        
        if (!root) return vector<int>{};
        
        solve(root);
        
        map<int,vector<int>,std::greater<int>> m;
        for (auto & p : counter)
            m[p.second].push_back(p.first);
        
        return m.begin()->second;
        
    }
};
```
