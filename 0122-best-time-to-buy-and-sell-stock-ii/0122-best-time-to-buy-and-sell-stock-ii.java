class Solution {
    public int maxProfit(int[] prices) {
        if(prices.length == 0) {
            return 0;
        }
        int sell = prices[0];
        int profit = 0;
        for(int i = 1; i < prices.length; i++) {
            if(prices[i] - sell > 0) {
                profit += prices[i] - sell;
                sell = prices[i];
            }
            if(sell > prices[i]) {
                sell = prices[i];
            }
        }
        return profit;
    }
}