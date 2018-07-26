/*
Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)
*/

/*
Note:
   for each item, result can be considered to be:
         pre (product of all items on the left) * post(product of all items on the right)
           

    i.e {2,3,4,5} -> {60,40,30,24}
    for 2, pre(no item) * post(3*4*5);
    for 3, pre(2) * post(4*5);
    for 4, pre(2*3) * post(5);
    for 5, pre(2*3*4) * post(no item);

    at beginning we set result to be {1,1,1,1} (so that we can multiply)
   - from left to right, we are calculating the pre products

      res[i] = nums[i-1]*res[i-1]; 

      starting from second elememt,( since 1st element does not have pre),
      each iteration we take one element and multiply it with its previous one.
      so for second elem, it is 2, for third elem, it is 2*3.

    after the iteration, res is {1,2,6,24}. This is what we have for pre for each element.
     
    - from right to left, we are calculating the post products.

       multiplier *=nums[i+1];

       similarly, multiplier will be the post product for each element.

       starting from second last element (since last element does not have post)
       multipliy its next elment to multiplier. 

       so for 4, multiplier (post) is 5
          for 3, multipler is 5*nums[i+1], which is 20.
          for 2, multiplier is 5*4*nums[i+1].

       in each iteration, after we find the post, we can multiply the post with pre:
       res[i] *= multiplier; 
 
       time: O(N) <- go through the array twice, 2N.   
       space: O(1) 
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        size_t len = nums.size();
        vector<int> res(len,1);
        //multiply from left to rigth, for pre
        for (int i = 1; i < len; i++){
            res[i] = nums[i-1]*res[i-1];
        }
        
        int multiplier = 1;
        for (int i = len-2; i >=0; i--){
            multiplier *= nums[i+1];
            res[i] *= multiplier;
        }
        return res;
    }
};
