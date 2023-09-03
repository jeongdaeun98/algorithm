import java.util.*;
import java.math.*;
class Solution {
    public int maxProfit(int[] prices) {
        int boughtStock = prices[0];
        int answer = 0;
        for(int i = 0; i < prices.length; i++) {
            answer = Math.max(answer, prices[i] - boughtStock);
            if(boughtStock > prices[i]) {
                boughtStock = prices[i];
            }
        }
        return answer;
    }
}