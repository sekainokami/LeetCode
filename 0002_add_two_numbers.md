### [2\. Add Two Numbers](https://leetcode.com/problems/add-two-numbers/)

Difficulty: **Medium**


You are given two **non-empty** linked lists representing two non-negative integers. The digits are stored in **reverse order** and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

**Example:**

```
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int sum = 0;
        int carry = 0;
        ListNode* curr = new ListNode(0);
        ListNode* head = curr;
        
        while (l1 || l2 || carry)
        {
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0;
            int s = carry + x + y;
            carry = s / 10;
​
            curr->next = new ListNode(s%10);
            curr = curr->next;
            
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        
        return head->next;
        
    }
};
```
