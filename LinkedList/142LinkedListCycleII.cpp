/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.

Follow up:
Can you solve it without using extra space?
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
   The distance between two pointer meet and start of cycle is same as from head to the start of the cycle:
   time: O(N+R) where R is length of loop
   space: O(1) no additional mem use except for the ptr

   If it takes K steps for slow pointer to meet fast pointer
   Fast pointer always takes 2K steps when they meet.This is because each step slow makes, fast makes 2 steps.

   let S indicate the steps from head to start of the loop ( we are looking for this)
   let R indicate the length of loop
   Notice S + R is the length of the list

   2K-S is steps fast in cycle
   K-S  is steps slow in cycle
  
   Since they meet at same place, fast ptr must go N times more cycle than slow ptr. Therefore:
   2K-s - (K-S) = N*R

   K = N*R

   regardless what N is, it is always the same place they points to since it is cycle. Therefore we can say
     K = R 
   
  plug in equation, S + K = length of the list

  This means, from the place they meet (K step away from head), it will take S steps to go back to the start of the loop.

  S is also indicating the steps from head to start of the loop.

  Therefore, after they meet, put one ptr to the head, it will take S steps for both ptr to reach the start of loop.
  This is where the ptr meets as well.
  */
  
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        bool isCycle = false;
        /* find whether there is a loop */
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast){
                isCycle = true;
                break;
            }
        }
        if(!isCycle) return NULL;
        
        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};

/*
Another solution using unordered_set to store address of each node
time O(N)
space O(N) <- need to store address for each node
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
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode *> nodeAddr;
        ListNode * ptr = head;
        while (ptr != NULL){
            if (nodeAddr.find(ptr) != nodeAddr.end()){
                return ptr;
            }else{
                nodeAddr.insert(ptr);
            }
            ptr = ptr->next;
        }
        return NULL;
    }
};
