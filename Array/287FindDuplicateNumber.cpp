/*
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Example 1:

Input: [1,3,4,2,2]
Output: 2
Example 2:

Input: [3,1,3,4,2]
Output: 3
Note:

You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.

*/

/*
Note:
    This is very similar the the linked list cycle, and the duplicate number is the entrance of the cycle.
    i.e [1,3,4,2,2]
    if we look at the element as index, as 1 -> 3 -> 2 -> 4 ->2 -> 4 this is a cycle at 2:

    1 -> 3 -> 2 -> 4
              ^    |
              |----|
    Therefore we still use slow faster pointers, eventually both pointer meets.
    then we reset one of the pointer to the beginning and both start go one step,
    then they will be meeing at entrance.
    
     what slow and fast stores in the array is same as what they are pointing to in the linked list
    since the question indicates that the array contains N+1 elements ranging from 1-N, nums[N] will be always valid. 

    time: O(N)
    space: O(1)
*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[nums[0]];
        
        while (slow != fast){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        fast = 0;
        while(slow != fast){
            fast = nums[fast];
            slow = nums[slow];
        }
        return fast;
    }
};
