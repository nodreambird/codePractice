/*
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:

Given the sorted linked list: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5
*/

/*
Note: to form balanced tree, insert the middle node and then split the node
      into two parts to insert children.
      Notice the edge, right child will start with middle->next
      Remember to pass both head and tail of each part of list. 
      space:O(n)
      runtime: T(n) = 2T(n/2) + c
               =  O(nlogn)
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode * sortListToBST(ListNode *head, ListNode *tail){
        if (head == tail) return nullptr;
        
        ListNode *mid = head;
        ListNode *temp = head;
        while(temp != tail && temp->next != tail){
            mid = mid->next;
            temp = temp->next->next;
        }
        TreeNode *root = new TreeNode(mid->val);
        root->left = sortListToBST(head,mid);
        root->right = sortListToBST(mid->next,tail);
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return sortListToBST(head, nullptr);
    }
};
