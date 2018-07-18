/*
Sort a linked list using insertion sort.


A graphical example of insertion sort. The partial sorted list (black) initially contains only the first element in the list.
With each iteration one element (red) is removed from the input data and inserted in-place into the sorted list
 

Algorithm of Insertion Sort:

Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list.
At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there.
It repeats until no input elements remain.

Example 1:

Input: 4->2->1->3
Output: 1->2->3->4
Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5
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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *newHead = NULL;
        ListNode *ptr = NULL;
        ListNode *cur = head;
        ListNode *p1, *p2;
        if (!head || !head->next) return head;
        
        while(cur != NULL){
            ptr = cur->next;
            if (newHead == NULL) {
                newHead = head;
                cur = ptr;
                newHead->next = NULL;
                continue;
            }
            p2 = newHead;
            while(p2){
                
                if(p2->val <= cur->val){
                    p1 = p2;
                    p2 = p2->next;            
                }else{
                    if (p2 == newHead){
                        newHead = cur;
                        cur->next = p2;
                    }else{
                        cur->next = p1->next;
                        p1->next = cur;
                    }
                    break;
                }
            }
            if (!p2){
                cur->next = p1->next;
                p1->next = cur;
            }
            cur = ptr;
            
        }
        return newHead;
    }
};
