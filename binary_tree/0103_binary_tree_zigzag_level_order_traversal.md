### [103\. Binary Tree Zigzag Level Order Traversal](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/)

Difficulty: **Medium**


Given a binary tree, return the _zigzag level order_ traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree `[3,9,20,null,null,15,7]`,

```
    3
   / \
  9  20
    /  \
   15   7
```

return its zigzag level order traversal as:

```
[
  [3],
  [20,9],
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root)
            return {};
        
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> res;
        int level = 0;
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
            
            if (level % 2)
                reverse(layer.begin(),layer.end());
            
            res.push_back(layer);
            level++;
        }
        
        return res;
    }
};
```
