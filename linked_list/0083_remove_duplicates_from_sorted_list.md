### [83\. Remove Duplicates from Sorted List](https://leetcode.com/problems/remove-duplicates-from-sorted-list/)

Difficulty: **Easy**


Given a sorted linked list, delete all duplicates such that each element appear only _once_.

**Example 1:**

```
Input: 1->1->2
Output: 1->2
```

**Example 2:**

```
Input: 1->1->2->3->3
Output: 1->2->3
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
    ListNode* deleteDuplicates(ListNode* head) {
        
        // dummy head to return the res
        ListNode* res = head;
        // keep comparing the current and next vals
        while (head && head->next)
        {
            // As long as the 2 vals are the same
            // Skip the next val
            while (head->next->val == head->val)
            {
                if (head->next->next)
                    head->next = head->next->next;
                else
                {
                    // No more values to continue the traversal
                    head->next = nullptr;
                    return res;
                }
            }
            
            head = head->next;
        }
        
        return res;
    }
};
```
