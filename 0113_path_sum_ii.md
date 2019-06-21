### [113\. Path Sum II](https://leetcode.com/problems/path-sum-ii/)

Difficulty: **Medium**


Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

**Note:** A leaf is a node with no children.

**Example:**

Given the below binary tree and `sum = 22`,

```
      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
```

Return:

```
[
   [5,4,11,2],
   [5,8,4,5]
]
```


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
public:
    
    vector<vector<int>> res;
    
    void solve(TreeNode* root, int sum, vector<int> curr)
    {
                
        curr.push_back(root->val);
        sum -= root->val;
        
        if (!root->left && !root->right && sum == 0)
        {
            res.push_back(curr);
            return;
        }
        
        if (root->left) solve(root->left,sum,curr);
        if (root->right) solve(root->right,sum,curr);
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        
        if (root == nullptr)
            return {};
        
        vector<int> curr;
        solve(root,sum,curr);
        return res;
        
    }
};
```
