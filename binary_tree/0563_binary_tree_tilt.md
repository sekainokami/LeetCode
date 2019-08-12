### [563\. Binary Tree Tilt](https://leetcode.com/problems/binary-tree-tilt/)

Difficulty: **Easy**


Given a binary tree, return the tilt of the **whole tree**.

The tilt of a **tree node** is defined as the **absolute difference** between the sum of all left subtree node values and the sum of all right subtree node values. Null node has tilt 0.

The tilt of the **whole tree** is defined as the sum of all nodes' tilt.

**Example:**

```
Input:
         1
       /   \
      2     3
Output: 1
Explanation:
Tilt of node 2 : 0
Tilt of node 3 : 0
Tilt of node 1 : |2-3| = 1
Tilt of binary tree : 0 + 0 + 1 = 1
```

**Note:**

1.  The sum of node values in any subtree won't exceed the range of 32-bit integer.
2.  All the tilt values won't exceed the range of 32-bit integer.


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
    // accumulate the tilt
    int res = 0;
    
    // dfs traversal
    int solve(TreeNode* root)
    {
        if (root == nullptr)
            return 0;
        // sum of all tree nodes from the left
        int left = solve(root->left);
        // sum of all tree ndoe from the right
        int right = solve(root->right);
        // calculate the tilt based on its definition
        res += left > right ? left - right : right - left;
        // return the sum of all nodes so far
        return left + right + root->val;
    }
    
    int findTilt(TreeNode* root) {
        solve(root);
        return res;
    }
};
```
