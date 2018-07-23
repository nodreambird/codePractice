/*
Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
Note: use a dummy node;
      use fast ptr to go 5 steps first. if it reaches end before 5, list not long enough
      Otherwise slow ptr now start at head and both ptr moves until ptr reaches end of list.
      now slow ptr will at the Nth node from end of list.
      use pre ptr to record previous node and perform deletion.
      time: O(n)
      space: O(1)
*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        ListNode *ptr = &dummy;
        ListNode *cur = &dummy;
        ListNode *pre;
        int i;
        
        dummy.next = head;
        
        for (i = 0; i < n && ptr; i++){
            ptr = ptr->next;
        }
        if (!ptr) return head;
        
        while (ptr){
            pre = cur;
            cur = cur->next;
            ptr = ptr->next;
        }
        pre->next = cur->next;
        delete cur;
        
        return dummy.next;
    }
};
