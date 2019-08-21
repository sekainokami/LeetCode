### [141\. Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/)

Difficulty: **Easy**


Given a linked list, determine if it has a cycle in it.

To represent a cycle in the given linked list, we use an integer `pos` which represents the position (0-indexed) in the linked list where tail connects to. If `pos` is `-1`, then there is no cycle in the linked list.


**Example 1:**

```
Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where tail connects to the second node.
```


<span style="display: inline;">![](https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist.png)</span>

**Example 2:**

```
Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where tail connects to the first node.
```


<span style="display: inline;">![](https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist_test2.png)</span>

**Example 3:**

```
Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.
```


<span style="display: inline;">![](https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist_test3.png)</span>

**Follow up:**

Can you solve it using _O(1)_ (i.e. constant) memory?


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
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> seen;
        while(head)
        {
            if (seen.find(head) != seen.end())
                return true;
            seen.insert(head);
            head = head->next;
        }
        return false;
    }
};
```
