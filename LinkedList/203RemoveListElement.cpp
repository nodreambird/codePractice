/*
Remove all elements from a linked list of integers that have value val.

Example:

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5

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
note if deleting the first element, need to change head
 time: O(N)
 space: O(1)
*/
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* cur = head;
        ListNode* pre = cur;
        
        while(cur){
            if (cur->val == val){
                if (cur == head){
                    head = cur->next;
                    delete cur;
                    cur = head;
                    pre = head;
                }else{
                    pre->next = cur->next;
                    delete cur;
                    cur = pre->next;
                }
            }else{
                pre = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};
