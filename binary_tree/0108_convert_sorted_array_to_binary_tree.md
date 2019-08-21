### [108\. Convert Sorted Array to Binary Search Tree](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/)

Difficulty: **Easy**


Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of _every_ node never differ by more than 1.

**Example:**

```
Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5
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
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) return nullptr;
        if (nums.size() == 1) return new TreeNode(nums[0]);
        
        int mid = nums.size() / 2;
        TreeNode* res = new TreeNode(nums[mid]);
        vector<int> l(nums.begin(),nums.begin()+mid);
        vector<int> r(nums.begin()+mid+1,nums.end());
        res->left = sortedArrayToBST(l);
        res->right = sortedArrayToBST(r);
        return res;
        
    }
};
```
