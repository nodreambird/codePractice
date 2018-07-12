/*
Given a linked list, swap every two adjacent nodes and return its head.

Example:

Given 1->2->3->4, you should return the list as 2->1->4->3.
Note:

Your algorithm should use only constant extra space.
You may not modify the values in the list's nodes, only nodes itself may be changed.

*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *prev = odd;

        head = even;
        while(odd && even){
            odd->next = even->next;
            even->next = odd;
            
            odd = odd->next;
            if(odd){
                even = odd->next;
            }else{
                even = nullptr;
            }
            if (even){
                prev->next = even;
                prev = odd;
            }
        }
        return head;
    }
};
