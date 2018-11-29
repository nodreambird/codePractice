
/*
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

Example:

Input:  [1,2,1,3,2,5]
Output: [3,5]
Note:

The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
*/

/*
Note:
   first xor all elememts, we get result of the two item xored.
   therefore the bit that is '1' in the result indicates that one of the two number set it, and the otherone did not.
   so we could find any bit in the result that is '1' and use it to separate it into two groups
   one with the bit on, and one with bit off.

   when you do (a & -a), you get the right most bit on only.
   this can be used to determin if a is power of 2:
   if (a = (a & -a)), a is power of 2.

   after separated groups, xor each group to get the number.
   space O(1);
   time  O(N);
*/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int val = 0;
        int v1 = 0, v2 = 0;
        vector<int> result;
        //xor all elements, now we have xored val of two single item
        for(int n:nums){
            val ^= n;
        }
        /* get the right most set bit */
        val &=  (-val);
        for(int m:nums){
            if ((val & m) == 0){
                v1 ^= m;
            }else{
                v2 ^=m;
            }
        }
        result.push_back(v1);
        result.push_back(v2);
        
        return result;
    }
};
