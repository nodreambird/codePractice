/*
Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false
Example 2:

Input: 1->2->2->1
Output: true
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
Method 1:
Note: use fast/slow pointer to find the middle of the list
      store values in first half into a stack
      compare values with second half
      notice the second half is different when there's even # of nodes and odd # of nodes.
      when odd # of nodes, slow points to the middle node, so move slow to its next.
     time: O(n)
     space: O(n) <- since store half of node value.
*/

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack <int> nodeVal;
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *ptr;
        int i;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        for (ptr = head; ptr != slow; ptr = ptr->next){
            nodeVal.push(ptr->val);
        }
        if (fast && !fast->next){
            //odd number of nodes
            slow = slow->next;
        }
        while(!nodeVal.empty() && slow){
            i = nodeVal.top();
            if (i != slow->val) return false;
            nodeVal.pop();
            slow = slow->next;
        }
        if (slow || !nodeVal.empty()) return false;
        return true;
    }
};

/*
Method 2:
   reverse first half of the list, then compare with the second half
   time:O(n)
   space:O(1)
*/
