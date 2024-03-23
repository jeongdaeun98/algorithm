// 1 1
// 0 * 1 = 1
// 2 2
// 0 * 1 = 1
// 1 * 0 = 1
// 3 5
// 0 * 2 = 2
// 2 * 0 = 2
// 1 * 1 = 1
// 4 14
// 0 * 3 = 5
// 3 * 0 = 5
// 1 * 2 = 2
// 2 * 1 = 2
// 5 
class Solution {
    public int numTrees(int n) {
        int dp[] = new int[n + 1];
        dp[0] = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = i - 1; j >= 0; j--){
                dp[i] += dp[j] *dp[i - j - 1];
            }
        }
        return dp[n];
    }
}