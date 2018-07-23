/*

Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
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
Note: if one of the list is longer than another, move ptrHA or ptrHB as new head
      so that ptrHA or ptrHB would start as same.
      i.e list A length 5
          List B length 3
          when b reaches the end, a still has to more to go.
          now move ptrHA forward, so that ptrHA and ptrHB will have same distance from the first sommon node

      then find the first node that has the same address
      time O(M+N)
      space O(1)
*/

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ptrHA=headA;
        ListNode *ptrHB=headB;
        ListNode *a = headA, *b = headB;
        
        while (a || b){
            if (!a){
                ptrHB= ptrHB->next;
            }else{
                a = a->next;
            }
            if (!b){
                ptrHA = ptrHA->next;
            }else{
                b = b->next;
            }
        }
        while(ptrHA && ptrHA != ptrHB){
            ptrHA = ptrHA->next;
            ptrHB = ptrHB->next;
        }
        return ptrHA;
        
    }
};
