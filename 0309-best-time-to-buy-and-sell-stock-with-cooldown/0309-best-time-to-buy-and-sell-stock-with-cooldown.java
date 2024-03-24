// buy[i] = Math.max(rest[i - 1] - prices[i], buy[i - 1])
// rest[i] = Math.max(buy[i - 1], rest[i - 1], sell[i - 1])
// sell[i] = Math.max(buy[i - 1] + prices[i], sell[i - 1])
// buy[i] = Math.max(sell[i - 2] - prices[i], buy[i - 1])
// prevBuy = buy0
// buy = Math.max(prevSell - prices[i], buy)1
// prevSell = sell 
// sell = Math.max(prevBuy + prices[i], sell)
class Solution {
    public int maxProfit(int[] prices) {
        int buy = Integer.MIN_VALUE, sell= 0, prevSell = 0, prevBuy = Integer.MIN_VALUE;
        for(int i = 0; i < prices.length; i++) {
            prevBuy = buy;
            buy = Math.max(prevSell - prices[i], buy);
            prevSell = sell;
            sell = Math.max(prevBuy + prices[i], sell);
        }
        return sell;
    }
}