/*
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.

Note:

Your returned answers (both index1 and index2) are not zero-based.
You may assume that each input would have exactly one solution and you may not use the same element twice.
Example:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
*/

/*
Note: first element + last element.
      if the sum is larger, move last ptr back 1 position.
      if the sum is smaller, move first ptr forward 1 position.
      this is because the array is sorted.
      time: O(n);
      space: O(1); 
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1;
        while (i < j) {
            int sum = numbers[i] + numbers[j];
            if (sum < target)
                i++;
            else if (sum > target)
                j--;
            else {
                return {i + 1, j + 1};
            }
        }
    }
};
/*
Note: use unordered_map to store the index that matches future match
      i.e {2,7,11,13} target=9
      in the temp map, store {(7.0)}. 7 is what number is needed for target, 0 is the index.
      time: O(n)
      space: worst case O(n) <- need to store all number until last one is match.
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        //if (numbers.size() < 2) return numbers;
        
        unordered_map<int,int> temp;
        vector<int> res;
        for (int i = 0; i < numbers.size(); i++){
            auto p = temp.find(numbers[i]);
            if (p == temp.end()){
                temp[target-numbers[i]] = i;
            }else{
                if (p->second > i){
                    res.push_back(i+1);
                    res.push_back(p->second+1);
                }else{
                    res.push_back(p->second+1);
                    res.push_back(i+1);
                }
                break;
            }
        }
        
        return res;
    }
};
