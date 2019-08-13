### [101\. Symmetric Tree](https://leetcode.com/problems/symmetric-tree/)

Difficulty: **Easy**


Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree `[1,2,2,3,4,4,3]` is symmetric:

```
    1
   / \
  2   2
 / \ / \
3  4 4  3
```

But the following `[1,2,2,null,3,null,3]` is not:

```
    1
   / \
  2   2
   \   \
   3    3
```

**Note:**
Bonus points if you could solve it both recursively and iteratively.


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
    bool isSymmetric(TreeNode* root) {
        
        if (!root) return true;
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            vector<int> layer;
            int sz = q.size();
            for (int i = 0; i < sz; ++i)
            {
                TreeNode* front = q.front();
                q.pop();
                if (front) q.push(front->left);
                if (front) q.push(front->right);
                if (front == nullptr)
                    layer.push_back(-1);
                else
                    layer.push_back(front->val);
            }
            
            vector<int> rlayer(layer.rbegin(),layer.rend());
            
            for (int j = 0; j < rlayer.size(); ++j)
            {
                if (rlayer[j] != layer[j]) return false;
            }
            
        }
        
        return true;
    }
};
```
