### [206\. Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/)

Difficulty: **Easy**


Reverse a singly linked list.

**Example:**

```
Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
```

**Follow up:**

A linked list can be reversed either iteratively or recursively. Could you implement both?


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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr)
        {
            // remember the next node
            ListNode* nxt = curr->next;
            // change the next node to the prev
            curr->next = prev;
            // now curr node is the prev node
            prev = curr;
            // curr node moves to the original next node
            curr = nxt;
        }
        
        return prev;
    }
};
```
