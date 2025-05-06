// # Best Time to Buy and Sell Stock

// **LeetCode:** 121  
// **Category:** Arrays, Sliding Window  
// **Difficulty:** Easy

// ## Problem Statement
// You're given an array `prices[]` where `prices[i]` is the stock price on day `i`.  
// Buy once and sell once to maximize profit.

// ## Approach
// - Use sliding window
// - Track min price (left pointer)
// - Calculate max profit with right pointer


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0;
        int right = 1;
        int maxProfit = 0;

        while(right < prices.size()){
            if(prices[right] > prices[left]){
                maxProfit = max(maxProfit, prices[right] - prices[left]);
            }
            else{
                left = right;
            }
            right++;
        }

        return maxProfit;
    }
};