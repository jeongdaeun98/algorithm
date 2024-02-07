// [1,2,3,0,2]
// buy[i] = Math.max(rest[i - 1] - prices, buy[i - 1])
// sell[i] = Math.max(buy[i - 1] + prices[i], sell[i - 1])
// rest[i] = Math.max(sell[i - 1], buy[i - 1], rest[i - 1])
// buy[i] + sell[i] + rest[i]
// buy = Math.max(sell[i - 2] - prices[i] , buy[i - 1])
// sell = Math.max(buy[i - 1] + prices[i], sell[i - 1])
// Math.max(buy[i - 2] - prices[i] , buy[i - 1]) + Math.max(buy[i - 1] + prices[i], sell[i - 1]) + buy[i - 1]

class Solution {
    public int maxProfit(int[] prices) {
        int prevBuy = Integer.MIN_VALUE, buy = Integer.MIN_VALUE, sell = 0, prevSell = 0;
        for(int i = 0; i < prices.length; i++){
            prevBuy = buy;
            buy = Math.max(prevSell - prices[i], buy);
            prevSell = sell;
            sell = Math.max(prevBuy + prices[i], sell);
        }
        return sell;
    }
}