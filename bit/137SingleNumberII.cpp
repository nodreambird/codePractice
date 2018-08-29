/*

Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,3,2]
Output: 3
Example 2:

Input: [0,1,0,1,0,1,99]
Output: 99
*/

/* general solution:
   assume most element appear k times
   special element appear p times;

  - we need log(k) counters to count all the bits for all elements
  - as a counter, for bit m to be true, its previous bits has to be true(so that it incremented to current bit)
    therefore for each bit, Xm = Xm ^(Xm-1 & Xm-2 & ... & X1)
  - for mask, every time a bit hit k times, it should be 0. if 2^m = k, that means it so happen all bits are used
    when k times are hit, so no need to do anything. if 2^m > k, that means every time we reach k times, we need 
    to reset it to 0. therefore mask it as reverse of the bit of k. 
    i.e if k = 5, it is 101 in binary, 
        we need m = log5 = 3, 2^3 = 8 > 5, so need to reset
        mask = ~(x1&~x2&x3);  <- as 101
  - apply mask to each counter:
        x3 = x3 & mask;
        x2 = x2 & mask;
        x1 = x1 & mask;
  - what to return:
    depends on what p is. if p = 4, as 100, then return x3 since 3rd bit is true;
    or we could return x3 | x2 | x1

   runtime: O(n) since only go through the array once.
   space: O(1) constant extra space
 
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        /* since log3 = 2, there will need to be 2 counters. */
        int x1 = 0, x2 = 0;
        int mask = 0;
        for (auto n:nums){
            x2 ^= x1 & n;
            x1 ^= n;
            /* since most iterm apear 3 times, as 011 in binary*/
            mask = ~(x1&x2);
            x2 &= mask;
            x1 &= mask;
        }
        /* since p = 1, return x1 */
        return x1;
    }
};

/* solution for this case:
   space: O(1)
   time: O(n)
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        /*consider counter as 00, 01, 10 
          x1 is first digit and x2 is second digit*/
        int x1 = 0, x2 = 0;
        
        for (auto n:nums){
            x2 = x2 ^ n & ~x1;
            x1 = x1 ^ n & ~x2;
        }
        return x1 | x2;
    }
};
