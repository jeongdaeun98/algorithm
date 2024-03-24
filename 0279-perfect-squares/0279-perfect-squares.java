// 1 1
// 2 1 + 1 = 2
// 3 2 + 1 = 3
// 4 4 = 1
// 5 4 1 = 2
// 6 4 2 = 3
// 7 4 3 = 4
// 8 4 4 = 2
// 9 4 5 = 2 + 1 = 3
// 12 
class Solution {
    public int numSquares(int n) {
        int dp[] = new int[n + 1];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[0] = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j * j <= i; j++) {
                dp[i] = Math.min(dp[i], dp[i - j*j] + 1);
            }
        }
        return dp[n];
    }
}