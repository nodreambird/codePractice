
/*
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

Example 1:

Input: [3,0,1]
Output: 2
Example 2:

Input: [9,6,4,2,3,5,7,0,1]
Output: 8
Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?

*/
/* solution 1: XOR
   since a ^b ^b = a;
   therefore we xor index with each element, and we will have the missing number since there's no match for that index
   Note that result set to num.size() because the loop stops before xor the largest element.
   time: O(n)
   space: O(1)
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int result = nums.size();
        for (int i = 0; i < nums.size(); i++){
            
            result = result ^ i ^ nums[i];
        }
        return result;
    }
};
/*
Note: Solution 2: Sum

add all numers, the difference is the missing number.
problem: both sum could overflow.

time: O(n)
space O(1);
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int rightSum;
        int sum = 0;
        int sz = nums.size();
        int result;
        
        for (int n:nums){
            sum += n;
        }
        rightSum = ((1+sz)*sz) >> 1;
        result = rightSum - sum;
        
        return result;
    }
};
