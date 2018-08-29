/*
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

/*
 in recursive call, index indicates the index of the item that we are trying to decide if put in the vector.
 i.e [1,2,3]

add    [1]?   [2]?      [3]?

                        yes {1,2,3}
               yes {1,2}
                        no  {1,2}
       yes {1}        
                        yes {1,3}
               no  {1}
                        no  {1}
{} 
                        yes {2,3}
               yes {2} 
                        no  {2}
       no  {}
                        yes {3}
               no  {}  
                        no  {}

 first we have empty set {}; 
 for each element we have to choices:
   a. put in the element i.e 1
   b. not put in  the element

 for a, we then need to consider if we need to put in next element, 2, so we would have either [1,2] or just [1]
        then we need to consider the next element. 
        once all elements are considered, remvove current element, which enters the b scenario.

 for b, we also need to consider if we need to put in next element, 2, so we would have either [2] or just []
 then we need to consider next level as well.
 time :O(2^n) for each element, we could go either take it or not take it, so it is 2^n

*/
class Solution {
public:
    void subset_rec(vector<int>& nums, vector<vector<int>> &res, vector<int> &sub, int index){    
        if (index == nums.size()){
            res.push_back(sub);
            return;
        }
        /* select next position to be filled */
        sub.push_back(nums[index]);
        subset_rec(nums,res,sub,index+1);
        /* select next position to not be filled */
        sub.pop_back();
        subset_rec(nums,res,sub,index+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> sub;
        subset_rec(nums, res, sub,0);
        return res;
    }

};

/* 
or 
*/
class Solution {
public:
    void subset_rec(vector<int>& nums, vector<vector<int>> &res, vector<int> &sub, int index){    
        res.push_back(sub);
        for (int i = index; i < nums.size(); i++){
            sub.push_back(nums[i]);
            subset_rec(nums,res,sub,i+1);
            sub.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> sub;
        subset_rec(nums, res, sub,0);
        return res;
    }

};
