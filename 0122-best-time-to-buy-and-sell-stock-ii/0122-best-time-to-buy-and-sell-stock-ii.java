class Solution {
    public int maxProfit(int[] prices) {
        int answer = 0;
        int boughtPrice = prices[0];
        int sellPrice = 0;
        for(int i = 1; i < prices.length; i++) {
            boughtPrice = Math.min(boughtPrice, prices[i]);
            sellPrice = Math.max(sellPrice, prices[i] - boughtPrice);
            if(sellPrice > 0) {
                answer += sellPrice;
                sellPrice = 0;
                boughtPrice = prices[i];
            }
        }
        return answer;
    }
}