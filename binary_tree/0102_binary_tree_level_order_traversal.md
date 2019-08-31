### [102\. Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/)

Difficulty: **Medium**


Given a binary tree, return the _level order_ traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree `[3,9,20,null,null,15,7]`,

```
    3
   / \
  9  20
    /  \
   15   7
```

return its level order traversal as:

```
[
  [3],
  [9,20],
  [15,7]
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root)
            return {};
        
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> res;
        while (!q.empty())
        {
            int sz = q.size();
            vector<int> layer;
            for (int i = 0; i < sz; ++i)
            {
                TreeNode* front = q.front();
                q.pop();
                layer.push_back(front->val);
                if (front->left) q.push(front->left);
                if (front->right) q.push(front->right);
            }
            
            res.push_back(layer);
        }
        
        return res;
    }
};
            
```
