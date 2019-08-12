### [21\. Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/)

Difficulty: **Easy**


Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

**Example:**

```
Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        // Create a dummy head
        ListNode* head = new ListNode(-1);
        ListNode* res = head;
        
        // Keep traversing through both l1 and l2
        while(l1 && l2)
        {
            // Get the smaller value
            int v1 = l1->val;
            int v2 = l2->val;
            int v = min(v1,v2);
            head->next = new ListNode(v);
            head = head->next;
            
            // Increment either l1 or l2 depending on which value
            // was smaller
            if (v1 < v2)
                l1 = l1->next;
            else
                l2 = l2->next;
        }
        
        // Extract the rest of the lists
        while (l1)
        {
            head->next = new ListNode(l1->val);
            head = head->next;
            l1 = l1->next;
        }
        
        while (l2)
        {
            head->next = new ListNode(l2->val);
            head = head->next;
            l2 = l2->next;
        }
        
        return res->next;
        
    }
};
```
