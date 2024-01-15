// 1. dp 로 n만큼 순회
// 2. dp[n - 순회 인덱스] + dp [인덱스]와 dp[n] 중 가장 작은 값으로 뒤바꿈
class Solution {
    public int numSquares(int n) {
        int dp[] = new int[n + 1];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[0] = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j * j <= i; j++){
                dp[i] = Math.min(dp[i - j * j] + 1, dp[i]);
            }
        }
        return dp[n];
    }
}