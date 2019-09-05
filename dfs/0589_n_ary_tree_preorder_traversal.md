### [589\. N-ary Tree Preorder Traversal](https://leetcode.com/problems/n-ary-tree-preorder-traversal/)

Difficulty: **Easy**


Given an n-ary tree, return the _preorder_ traversal of its nodes' values.

For example, given a `3-ary` tree:

![](https://assets.leetcode.com/uploads/2018/10/12/narytreeexample.png)

Return its preorder traversal as: `[1,3,5,6,2,4]`.

**Note:**

Recursive solution is trivial, could you do it iteratively?


#### Solution

Language: **C++**

```c++
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;
​
    Node() {}
​
    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    
    vector<int> res;
    
    void solve(Node* root)
    {
        if (!root) return;
        res.push_back(root->val);
        for (int i = 0; i < root->children.size(); ++i)
            solve(root->children[i]);
    }
    
    vector<int> preorder(Node* root) {
        if (!root) return vector<int>{};
        solve(root);
        return res;
    }
};
```
