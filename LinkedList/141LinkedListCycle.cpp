/*
Given a linked list, determine if it has a cycle in it.

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
 note: use a faster pointer goes twice fast, if it catches slow pointer, there is a loop.
*/
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *cur = head;
        ListNode *faster = head;
        
        while(faster!=nullptr && faster->next != nullptr ){
            
            cur = cur->next;
            faster = faster->next->next;
            if (faster == cur ) break;
        }
        if (!faster || !faster->next) return false;
        if (faster == cur) return true;
    }
};

/* also could use unordered map to store address of each node and check */
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
                return true;
            }else{
                nodeAddr.insert(ptr);
            }
            ptr = ptr->next;
        }
        return false;
    }
};
