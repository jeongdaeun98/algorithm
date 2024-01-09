class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int[][] dp = new int[obstacleGrid.length][obstacleGrid[0].length];
        if(obstacleGrid[0][0] == 1) {
            return 0;
        }
        for(int i = 0; i < obstacleGrid.length; i++) {
            if(obstacleGrid[i][0] == 1 || (i > 0 && dp[i - 1][0] == 0)) {
                dp[i][0] = 0;
            } else {
                dp[i][0] = 1;
            }
            for(int j = 0; j < obstacleGrid[i].length; j++) {
                if(obstacleGrid[0][j] == 1|| (j > 0 && dp[0][j - 1] == 0)) {
                dp[0][j] = 0;
                } else {
                dp[0][j] = 1;
                }
                if(i == 0 || j == 0) {
                    continue;
                }
                if(obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        if(obstacleGrid[obstacleGrid.length - 1][obstacleGrid[0].length - 1] == 1) {
            return 0;
        }else {
            return dp[obstacleGrid.length - 1][obstacleGrid[0].length - 1];
        }
    }
}