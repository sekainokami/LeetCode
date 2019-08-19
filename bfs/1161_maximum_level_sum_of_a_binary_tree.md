### [1161\. Maximum Level Sum of a Binary Tree](https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/)

Difficulty: **Medium**


Given the `root` of a binary tree, the level of its root is `1`, the level of its children is `2`, and so on.

Return the **smallest** level `X` such that the sum of all the values of nodes at level `X` is **maximal**.

**Example 1:**

**![](https://assets.leetcode.com/uploads/2019/05/03/capture.JPG)**

```
Input: [1,7,0,7,-8,null,null]
Output: 2
Explanation:
Level 1 sum = 1.
Level 2 sum = 7 + 0 = 7.
Level 3 sum = 7 + -8 = -1.
So we return the level with the maximum sum which is level 2.
```

**Note:**

1.  The number of nodes in the given tree is between `1` and `10^4`.
2.  `-10^5 <= node.val <= 10^5`


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
    int maxLevelSum(TreeNode* root) {
        
        int res = 1;
        int curr = 1;
        int max_sum = INT_MIN;
        
        queue<TreeNode*> Q;
        Q.push(root);
        
        while (!Q.empty())
        {
            int sz = Q.size();
            int layer_sum = 0;
            for (int i = 0; i < sz; ++i)
            {
                TreeNode* front = Q.front();
                Q.pop();
                layer_sum += front->val;
                if (front->left) Q.push(front->left);
                if (front->right) Q.push(front->right);
            }
            
            if (layer_sum > max_sum)
            {
                max_sum = layer_sum;
                res = curr;
            }
            curr ++;
        }
        
        return res;
        
    }
};
```
