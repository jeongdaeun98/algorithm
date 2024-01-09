//1. 오른쪽, 아래쪽으로 가는 방법은 무조건 하나이니까 일단 왼쪽이나 오른쪽 index가 0인 애들은 0이 아닌 인덱스 - 1 의 값과 더함
//2. 위의 경우가 아닌 인덱스의 애들은 저장된 값 중 가장 작은 값과 더해줌
class Solution {
    public int minPathSum(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0) {
                    continue;
                }
                if(j == 0) {
                    grid[i][j] += grid[i - 1][j];
                }else if(i == 0) {
                    grid[i][j] += grid[i][j - 1];
                } else {
                    grid[i][j] += Math.min(grid[i - 1][j], grid[i][j - 1]);
                }
            }
        }
        return grid[m - 1][n - 1];
    }
}