class Solution {
    public int maxProfit(int[] prices) {
        int profit = 0;
        int sell = prices[0];
        for(int i = 1; i < prices.length; i++) {
            profit = Math.max(profit,prices[i] - sell);
            sell = Math.min(sell, prices[i]);
        }
        return profit;
    }
}