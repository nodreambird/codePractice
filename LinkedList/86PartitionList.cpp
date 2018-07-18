/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

Example:

Input: head = 1->4->3->2->5->2, x = 3
Output: 1->2->2->4->3->5
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//two ways.
/*
Note: split the list to two halves, less than x and larger (or equal to) x.
      go through the list and assign each node to two halves accordingly.
      combine list in the end
      time: O(n)
      space: O(1)
*/
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *less = NULL, *lessPtr = NULL;
        ListNode *larger = NULL, *largerPtr = NULL;
        ListNode *cur = head, *temp = NULL;
        
        while(cur != NULL){
            temp = cur->next;
            if (cur->val < x){
                if (!less){
                    less = cur;
                    
                }else{
                    lessPtr->next = cur;
                }
                lessPtr = cur;
            }else{
                if (!larger){
                    larger = cur;
                }else{
                    largerPtr->next = cur;
                }
                largerPtr = cur;
            }
            cur->next = NULL;
            cur = temp;
        }
        
        if (!less) return larger;
        if (!larger) return less;
        
        lessPtr->next = larger;
        return less;
        
        
    }
};

/*
Another way: use dummy node as head for each list
   time: O(n);
   space: O(1);
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
    ListNode* partition(ListNode* head, int x) {
        ListNode node0(0);
        ListNode node1(1);
        
        ListNode *less = &node0;
        ListNode *larger = &node1;
        ListNode *cur = head;
        
        while(cur){
            if (cur->val < x){
                less->next = cur;
                less = cur;
            }else{
                larger->next = cur;
                larger = cur;
            }
            cur = cur->next;
        }
        larger->next = NULL;
        less->next = node1.next;
        
        return node0.next;
        
        
        
    }
};
