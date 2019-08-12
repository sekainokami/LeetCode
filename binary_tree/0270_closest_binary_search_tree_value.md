### [270\. Closest Binary Search Tree Value](https://leetcode.com/problems/closest-binary-search-tree-value/)

Difficulty: **Easy**


Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.

**Note:**

*   Given target value is a floating point.
*   You are guaranteed to have only one unique value in the BST that is closest to the target.

**Example:**

```
Input: root = [4,2,5,1,3], target = 3.714286

    4
   / \
  2   5
 / \
1   3

Output: 4
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
    
    int ret;
    double min = numeric_limits<double>::max();
    
    void solve(TreeNode* root, double target)
    {
        if (root == nullptr)
            return;
        
        if (abs(root->val-target) < min)
        {
            min = abs(root->val-target);
            ret = root->val;
        }
​
        if (root->val == target)
            return;
        else if (root->val < target)
            solve(root->right,target);
        else
            solve(root->left, target);
​
    }
    
    
    int closestValue(TreeNode* root, double target) {
        
        solve(root,target);
        return ret;
    }
};
```
