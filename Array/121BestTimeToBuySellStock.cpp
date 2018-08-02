/*

Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.

Example 1:

Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
             Not 7-1 = 6, as selling price needs to be larger than buying price.
Example 2:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.

*/

/*
 Note:
   use two pointers, one points to beginning, one points to next;

   if prices[end] - prices[begin] > 0, move end forward
     this is to find continuous increasing subarray, record the largest profit 
   if prices[end] - prices[begin] <= 0, move begin to end position
     this is to start to find a new continuous increasing subarray.
   space: O(1)
   time: O(n)
 
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 0) return 0;
        int begin,end,temp;
        int profit = 0;
        begin = 0;
        end = begin+1;
        
        while(end < prices.size()){
            temp = prices[end] - prices[begin];
            if (temp > 0){
                
                if (temp > profit) profit = temp;
            }else{
                begin = end;
            }
            end++;
        }
        return profit;
    }
};
/*
Note: 
   space: O(1)
   time: O(n)
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 0) return 0;
        
        int buy =prices[0];
        int sell = prices[0];
        int profit = 0;
        int buy2 = -1;
        for (int p = 1; p < prices.size(); p++){
            if (prices[p] > buy){
                if (sell < prices[p]){
                    profit = prices[p] - buy;
                    sell = prices[p];
                }
                if ( buy2 != -1){
                    if (profit < prices[p] - buy2){
                        profit = prices[p]- buy2;
                        buy = buy2;
                        sell = prices[p];
                        buy2 = -1;
                    }
                }
            }else{
                if (buy2 == -1 || prices[p]<buy2){
                    buy2 = prices[p];
                    continue;
                }
                if (prices[p] - buy2 > profit){
                    buy = buy2;
                    sell = prices[p];
                    profit = sell - buy;
                    buy2 = -1;
                }
                
            }
        }
        return profit;
    }
};
