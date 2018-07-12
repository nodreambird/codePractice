/*
 Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
Follow up:

A linked list can be reversed either iteratively or recursively. Could you implement both?

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
    ListNode* reverseList(ListNode* head) {
        if (!head) return nullptr;
        if (!head->next) return head;
        ListNode *prev, *cur, *temp;
        
        prev = head;
        cur = head->next;
        prev->next = nullptr;
        do{
            temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }while(temp);
        
        return prev;
    }
};

/* consider 

  NULL 1 -> 2->3->4
   |   |    |
 pre   cur  temp

we can shorten the answer to:

*/

    ListNode* reverseList(ListNode* head) {
        if (!head) return nullptr;
        if (!head->next) return head;
        ListNode *prev, *cur, *temp;
    
        prev = nullptr;
        cur = head;
        while (cur){
           temp = cur->next;
           cur ->next = prev;
           prev = cur;
           cur = temp;

        }
        return prev;
    }

/* recursive:

   store next node to NX, and change ptr to point to prev
   recursively call, now NX is cur, prev is old cur, until cur is nullptr, 
   then we return prev as head;

 */
   ListNode *recurList(ListNode* cur, ListNode *newHead){
      if (!cur) return newHead;
      
      listNode *NX = cur->next;
      cur->next = newHead;
      
      return recurList(NX, cur);
     
   }
    ListNode* reverseList(ListNode* head) {
        
        return recurList(head,nullptr);
    }
