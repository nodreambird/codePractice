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

/* method 1
Note:
   use boyer-moore vote algorithm
   i.e [1,1,1, 2, 3 ]
   for each 1, look for next different element to 'cancel' its count.
   when meet 2, counter -1, when meet 3, counter -1, since counter still not 0, we know 1 is most frequent.
   
   then we need to check if 1 actually fits the requirement, which is repeated larger than n/2.
   if we know there must be a solution exist, we don't need to do the check.
   time: O(n) <- loop through array once( or twice)
   space: O(1)
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int counter = 0;
        for (int i:nums){
            if (i == candidate){
                counter++;
            }else if(counter == 0){
                candidate = i;
                counter = 1;
            }else{
                counter--;
            }
        }
        counter = 0;
        for (int i:nums){
            if (i == candidate) counter ++;
        }
        if (counter > nums.size()/2){
            return candidate;
        }
    }
};
/*
method 2
Note:
   use a unordered map to store the unique element and # of times it repeated.
   then search through the map and find the element that apears more than n/2
   space: O(n) <- need to store # repeated for each unique element
   time: O(n) <- need to go through entire array

Method 3 takes time :O(nlogn) 
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
