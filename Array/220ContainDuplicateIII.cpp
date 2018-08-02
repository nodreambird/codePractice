/*
Given an array of integers, find out whether there are two distinct indices i and j in the array such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.

Example 1:

Input: nums = [1,2,3,1], k = 3, t = 0
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1, t = 2
Output: true
Example 3:

Input: nums = [1,5,9,1,5,9], k = 2, t = 3
Output: false
*/
/*
note:
     keep a window of size k, erase values far from k.
     lower_bound returns the smallest element that is larger or equal to the input.
     pos should points to the smallest element that is larger or equal to (nums[i] - t)
     if there is such pos, we found the value and return true;
      
     note that nums[i] could be negative, and it could overflow. therefore use long long to avoid overflow.
     we need to check again if the difference between pos and num[i] is <=t, because we could find a pos that is 
     very large. 
     if no such pos found, insert val and try next element.
     

     space:O(n); 
     time: O(nlogn) this is because we need to go through entire nums, and for each num, 
                    lower_bound takes logn time.
*/
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (nums.size() < 2 || k == 0) return false;
        
        set <long long>dupNum;
        for (int i = 0; i < nums.size(); i ++){
            if (i > k) dupNum.erase(nums[i-k-1]);
            
            auto pos = dupNum.lower_bound((long long)nums[i] - (long long)t);
            
            if (pos != dupNum.end() && abs((long long)nums[i] - *pos) <= (long long)t)
                return true;
            dupNum.insert(nums[i]);
        }
        return false;
    }
};
