// minAndMax 알고리즘
// 2 7 9 4 4
// 26 24 17 8 4
// Alice a , Bob b
// a 1, M 1 -> b 1 *2*
// a 2, M 2 -> b 2 *3* /4
class Solution {
    public int stoneGameII(int[] piles) {
        int[] prefix = new int[piles.length];
        prefix[piles.length - 1] = piles[piles.length - 1];
        for(int i = piles.length - 2; i >= 0; i--) {
            prefix[i] = piles[i] + prefix[i + 1];
        }
        int[][] dp = new int[piles.length][piles.length];
        return dfs(piles, prefix, dp, 1, 0);
    }
    public int dfs(int[] piles, int[] prefix, int[][]dp, int M, int i) {
        if(i == piles.length) {
            return 0;
        } 
        if(i + 2 * M >= piles.length) {
            return prefix[i];
        }
        if(dp[i][M] != 0) {
            return dp[i][M];
        }
        int result = 0;
        for(int x = 1; x <= 2* M; x++) {
            result = Math.max(result, prefix[i] - dfs(piles, prefix, dp, Math.max(M, x), i + x));
        }
        dp[i][M] = result;
        return result;
    }
}