/*
Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.

Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1
Output: true
Example 3:

Input: nums = [1,2,3,1,2,3], k = 2
Output: false

*/

/*
Note: use unordered_set to store k elements.
      erase any element that is more than k away for current ptr, since it is not needed.
      set cannot store duplicate value. if a duplicate is trying to insert to the set,
      the ::second will be set to 0 if insertion failed.
      time: O(n)
      space: O(n)
*/
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (nums.size()<2 || k == 0) return false;
        
        //count num and indecies.
        unordered_set <int> dupNum; 
        for (int i = 0; i < nums.size();i++){
            // erase elements k away from current ptr
            if (i > k) dupNum.erase(nums[i-k-1]);
            if (!dupNum.insert(nums[i]).second) return true;
        }
        return false;
    }
};
/*
Note:
   use unordered_map to pair each num with its index.
   if an element has already had an index, check if it is within k range by substract.

   note here at beginning map is init to 0, which means all element is paired with first index.
   this could cause trouble when duplicate with first element.
   so add 1 to each index when store to map, but remember to substract 1 when checking range.
   time:O(N)
   space:O(nlogn)
*/
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (nums.size()<2 || k == 0) return false;
        
        //count num and indecies.
        unordered_map <int,int> count; 
        int index;
        for (int i = 0; i < nums.size();i++){
            index = count[nums[i]];
            if (index){
                if (i - index+1 <= k) return true;
                else count[nums[i]] = i+1;
            }else{
                count[nums[i]] = i + 1; 
            }
        }
        return false;
    }
};
