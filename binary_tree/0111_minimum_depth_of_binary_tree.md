### [111\. Minimum Depth of Binary Tree](https://leetcode.com/problems/minimum-depth-of-binary-tree/)

Difficulty: **Easy**


Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

**Note:** A leaf is a node with no children.

**Example:**

Given binary tree `[3,9,20,null,null,15,7]`,

```
    3
   / \
  9  20
    /  \
   15   7
```

return its minimum depth = 2.


#### Solution

Language: **C++**

```c++
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // DFS
    int minDepth(TreeNode* root) {
        if (!root){
            return 0;
        }
        if (!root->left){
            return minDepth(root->right) + 1;
        }
        if (!root->right){
            return minDepth(root->left) + 1;
        }
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
    
    /* BFS
        int minDepth(TreeNode* root) {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return 1;
        
        std::queue<TreeNode*> q;
        q.push(root);
        int level = 1;
        TreeNode* node = nullptr;
        while (!q.empty())
        {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; i++)
            {
                node = q.front();
                if (!node->left && !node->right)
                    return level;
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
                q.pop();
            }
            level++;
            
        }
        return level;
    }
    */
};
```
