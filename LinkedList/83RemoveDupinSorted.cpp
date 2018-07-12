/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

Example 1:

Input: 1->1->2
Output: 1->2
Example 2:

Input: 1->1->2->3->3
Output: 1->2->3
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
  stay at current node and check next
  if value is same, remove next
  if value is not same, move to next node.
*/

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *cur = head;
        ListNode *nxt;
        if (!head || !head->next) return head;
        
        while(cur->next){
            nxt = cur->next;
            if (nxt->val == cur->val){
                cur->next = nxt->next;
                delete nxt;
            }else{
                cur = cur->next;
            }
        }
        return head;
    }
};
