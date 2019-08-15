### [98\. Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/)

Difficulty: **Medium**


Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

*   The left subtree of a node contains only nodes with keys **less than** the node's key.
*   The right subtree of a node contains only nodes with keys **greater than** the node's key.
*   Both the left and right subtrees must also be binary search trees.

**Example 1:**

```
    2
   / \
  1   3

Input: [2,1,3]
Output: true
```

**Example 2:**

```
    5
   / \
  1   4
     / \
    3   6

Input: [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
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
    
    // Inorder traversal of BST results in a sorted array
    
public:
    vector<int> v;
    
    void dfs(TreeNode* root)
    {
        if (!root) return;
        dfs(root->left);
        v.push_back(root->val);
        dfs(root->right);
    }
    
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        
        dfs(root);
        
        for (int i = 1; i < v.size(); ++i)
        {
            if (v[i] <= v[i-1])
                return false;
        }
        
        return true;
        
    }
};
```
