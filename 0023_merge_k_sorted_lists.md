### [23\. Merge k Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists/)

Difficulty: **Hard**


Merge _k_ sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

**Example:**

```
Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
```


#### Solution

Language: **C++**

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        // Standard traveral all lists and record all values
        // Sort the values
        // Generate the resulted list
        
        if (lists.empty())
            return nullptr;
        
        if (lists.size() == 1)
            return lists[0];
        
        vector<int> vals;
        
        for (auto & list : lists)
        {
            while (list)
            {
                vals.push_back(list->val);
                list = list->next;
            }
        }
        
        sort(vals.begin(),vals.end());
        
        ListNode* curr = new ListNode(-1);
        ListNode* res = curr;
        
        for (auto& v: vals)
        {
            curr->next = new ListNode(v);
            curr = curr->next;
        }
        
        return res->next;
​
    }
};
```
