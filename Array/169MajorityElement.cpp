/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2
*/

/*
method 1
Note:
   use a unordered map to store the unique element and # of times it repeated.
   then search through the map and find the element that apears more than n/2
   space: O(n) <- need to store # repeated for each unique element
   time: O(n) <- need to go through entire array

Method 2 takes time :O(nlogn) 
         but space: O(1);

*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> countElem;
        size_t len = nums.size();
        int ans;
        
        for (int i = 0; i < len; i++){
            auto ptr = countElem.find(nums[i]);
            if (ptr != countElem.end()){
                (ptr->second)++;
            }else{
                countElem[nums[i]] = 1; 
            }
        }
        for (auto iter = countElem.begin(); iter != countElem.end(); iter++){
            if (iter->second > (len/2)){
                ans = iter->first;
            }
        }
        return ans;
    }
};
/*method 2:
  if a number is repeated more than n/2, once we sort the array, the n/2 element must be the majority
  space: O(1)
  time:  O(nlogn) <- sort takes nlogn times
  
  nth_element(iter first, iter nth, iter end) is a partial sorting algorithm, requires<algorithm>
        the element pointed by 'nth' will be the exact location when the array is sorted.
        all elements befor 'nth' is less than or equal to new 'nth' element
              
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        size_t len = nums.size();
        nth_element(nums.begin(), nums.begin()+len/2, nums.end());
        return nums[len/2];
    }
};
