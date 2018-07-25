/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
Note:

You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/


/*
 faster solution:
   go through the array, if we see n zero,
   that means the next non-zero needs to shift n position 
   so put current value to the position after shift, and mark current value to 0

   Notice that if we haven't seen any 0, do not shift.

   i.e 8006009
   number 8 stay because we haven't seen 0.
   number 6 needs to be shift 2 position to the front, because we have seen 2 0s.
   number 9 needs to be shift 4 positions front, because we seen 4 0s

   the position after shift is just index - shift.

   time: O(n)
   space: O(1)
   
*/
class Solution {

public:
    void moveZeroes(vector<int>& nums) {
        int shift = 0;
        int curPos = 0;
        while(curPos < nums.size()){
            if( nums[curPos] == 0){
                shift++;
            }else{
                if (shift == 0){
                    curPos++;
                    continue;
                }else{
                    nums[curPos-shift] = nums[curPos];
                    nums[curPos] = 0;
                }
            }
            curPos ++;
        }
    }
};
/*
Note:
   starting from current position,
   find the first non-zero position, and assign its value to current position.
   if current position is not 0, it will assign value to itself  
   if current position is 0, we can swith the first non-zero content to current position.
   if non-zero position is larger than the size of the vector, all remaining pos are 0.
*/
class Solution {

public:
    void moveZeroes(vector<int>& nums) {
        int nzLoc = 0;
        int curPos = 0;
        while(curPos < nums.size() && nzLoc < nums.size()){
            while(nums[nzLoc] == 0) 
                nzLoc ++;
            if (nzLoc >= nums.size()){
                break;
            }else{
                nums[curPos] = nums[nzLoc];
                if (curPos != nzLoc) nums[nzLoc] = 0;
                curPos ++;
                nzLoc = curPos;
            }
        }
    }
};
