// 1. buy sell rest로 저장소를 나누어서 가장 큰 값으로 갱신한다.
// 2. buy[i] = Math.max(rest[i - 1] - prices, buy[i - 1]);
// 3. sell[i] = Math.max(buy[i - 1] + prices, sell[i - 1]);
// 4. rest[i] = Math.max(buy[i - 1], sell[i - 1], rest[i - 1]);
// 5. rest의 경우 buy[i - 1] <= rest[i - 1] <= sell[i - 1]
// 6. rest[i] = sell[i - 1]이다.
// 7. buy[i] = Math.max(sell[i - 2] - prices, buy[i - 1]);
// 8. sell[i] = Math.max(buy[i - 1] + prices, sell[i - 1]);

class Solution {
    public int maxProfit(int[] prices) {
        int sell = 0, prevSell = 0;
        int buy = Integer.MIN_VALUE, prevBuy = Integer.MIN_VALUE;
        for(int i = 0; i < prices.length; i++) {
            prevBuy = buy;
            buy = Math.max(prevSell - prices[i], prevBuy);
            prevSell = sell;
            sell = Math.max(prevBuy + prices[i], prevSell);
        }
        return sell;
    }
}