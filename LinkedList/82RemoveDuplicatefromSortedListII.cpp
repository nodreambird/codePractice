/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

Example 1:

Input: 1->2->3->3->4->4->5
Output: 1->2->5
Example 2:

Input: 1->1->1->2->3
Output: 2->3
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
Note:
   since sorted, check if next node is same as current.
   if so remove current node, and set flag to remove the last node with same val.
   rm the node even if value from next node is different as long as flag is set.
   create a dummy node to make things simpler
   time: O(n)
   space: O(n)
*/
class Solution {
private:
    void deleteNode(ListNode **cur, ListNode **pre){
        (*pre)->next = (*cur) -> next;
        delete *cur;
        *cur = (*pre)->next;
    }
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        ListNode *pre = &dummy;
        ListNode *cur = head;
        dummy.next = head;
        bool rm = false;
        
        while(cur){
            if (cur->next && cur->next->val == cur->val){
                deleteNode(&cur,&pre);
                rm = true;
            }else{
                if (rm){
                    deleteNode(&cur,&pre);
                    rm = false;
                }else{
                    pre = cur;
                    cur = cur->next;
                }
            }
        }
        return dummy.next;
    }
};
