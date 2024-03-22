// prefix sum,min max 알고리즘
// 가장 최상의 경우를 찾는 것, 그런데 주어진 케이스 중 가장 큰 경우의 수를 찾아야 함.
// [2,7,9,4,4]
// 뒤부터 누적합으로 더해줌
// [26,24,17,8,4]
// A 앨리스 B 밥
// A -> 1, 2
// B -> A가 1, 1,*2* A가 2, 2,*3*,4 , 
// 즉, A가 선택한개수를 M라 하면 i + 2 * 2 >= piles.length 일 때, 누적합 i로 리턴
// A -> 
class Solution {
    public int stoneGameII(int[] piles) {
        int[] prefix = new int[piles.length];
        prefix[piles.length - 1] = piles[piles.length - 1];
        for(int i = piles.length - 2; i >= 0; i--) {
            prefix[i] = piles[i] + prefix[i + 1];
        }
        int dp[][] = new int[piles.length][piles.length];
        
        return dfs(piles, prefix, dp, 1, 0);
    }
    public int dfs(int[] piles, int[] prefix,int[][]dp, int M, int i){
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
        for(int x= 1; x<= 2*M; x++) {
            result = Math.max(result, prefix[i] - dfs(piles, prefix, dp, Math.max(M,x), i + x));
        }
        dp[i][M] = result;
        return result;
    }
}