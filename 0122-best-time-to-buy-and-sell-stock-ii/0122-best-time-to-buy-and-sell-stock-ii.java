class Solution {
    public int maxProfit(int[] prices) {
        int answer = 0;
        int sell = prices[0];
        for(int i = 1; i < prices.length; i++) {
            if(prices[i] - sell > 0) {
                answer += prices[i] - sell;
            }
            sell = prices[i];
        }
        return answer;
    }
}