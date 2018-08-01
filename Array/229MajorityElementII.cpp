/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Note: The algorithm should run in linear time and in O(1) space.

Example 1:

Input: [3,2,3]
Output: [3]
Example 2:

Input: [1,1,1,3,3,2,2,2]
Output: [1,2]
*/

/*
Note:
   use Boyer-Moore vote algorithm
   idea is that if a candidate is selected, there is other element to 'cancel' this candidate.
   in this case, majority is repeated more than n/3, then max there are two element can fit the requirement.
   therefore we need two candidate and counter.
 
  notice:
  1. we need to first check the element is not cad1 or cad2, then we check counters.
   if we check counter1(or count2) == 0 first, it is possible that cad1 and cad2 has the save value.
    [4,4,4,4]
   i.e if cad1 = 4 and count1 = 1,
          cad2 = 0 and count2 = 0,
       if we check count2 == 0 first, cad2 will be updated to 4, which in this case we should update counter1.
  2. we need to initialize cad2 different from cad1. if both init to '0', if input vecor is [0,0,0]
     bot cad1 and cad2 would have same valid input. 

   after counting, it is possible that two candidates are not valid.
   we need to do another check to make sure they are right. 
   time: O(N) <- loop through array twice
   space: O(1) <- only use const var.
*/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cad1, cad2,count1,count2;
        vector<int> res;
        cad1 = 0;
        cad2 = 1;
        count1 = 0;
        count2 = 0;
        for (auto i:nums){
            if(i == cad1){
                count1++;
            }else if(i == cad2){
                count2++;
            }else if(count1 == 0){
                cad1 = i;
                count1 = 1;
            }else if(count2 == 0){
                cad2 = i;
                count2 = 1;
            }else{
                count1 --;
                count2 --;
            }
        }
        count1 = 0;
        count2 = 0;
        for (auto j:nums){
            if (j == cad1) count1++;
            if (j == cad2) count2++;
        }
         /* if we give size of vector res, then we could use index.
            in this case, we are not certain there's 1 or 2 items.
            therefore use push_back. */
        if (count1 > nums.size()/3){
            res.push_back(cad1);
        }
        if (count2 > nums.size()/3){
            res.push_bakc(cad2);
        }
        return res;
    }
};
