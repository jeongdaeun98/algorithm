class Solution {
    public int climbStairs(int n) {
        int[] stair = new int[n + 1];
        if( n  <= 2) {
            return n;
        }
        stair[1] = 1;
        stair[2] = 2;
        
        for(int i = 3; i <= n; i++) {
            stair[i] = stair[i - 1] + stair[i - 2];
        }
        return stair[n];
    }
}